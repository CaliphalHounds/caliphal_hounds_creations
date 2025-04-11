from flask import Flask, request, render_template, redirect, url_for, session
from flask_login import LoginManager, UserMixin, login_required, login_user, current_user
from db import DatabaseController
from hashlib import sha256
from flag import FLAG
from re import search

app = Flask(__name__)
app.config['SECRET_KEY'] = "Jqe?iXh/N/&5-5=bd#E'4}D2.Vz$Io2A%=OF2DXy/[a7Uq.)RC"

login_manager = LoginManager(app)
login_manager.login_view = "get_login"

db = DatabaseController()



class User(UserMixin):
    def __init__(self, id, username, password):
         self.id = id
         self.username = username
         self.password = password
         self.authenticated = False

    def is_active(self):
         return self.is_active()

    def is_anonymous(self):
         return False

    def is_authenticated(self):
         return self.authenticated

    def is_active(self):
         return True

    def get_id(self):
         return self.id

@login_manager.user_loader
def load_user(id):
    user = db.getUserById(id)
    if user is None:
        return None
    else:
        return User(user["id"], user["username"], user["password"])


def filterFlag(posts):
    res = [p for p in posts if p[1] != FLAG]
    return res



@app.route('/', methods=['GET'])
def route():
    return redirect(url_for("get_login"))


@app.route('/login', methods=['GET'])
def get_login():
    return render_template("login.html", login_page=True)


@app.route('/login', methods=['POST'])
def post_login():
    username = request.form.get("username")
    password = request.form.get("password")

    if not username or not password:
        return render_template("login.html", error="Invalid credentials!", login_page=True)

    user = db.checkPassword(username, sha256(password.encode()).hexdigest())

    if user:
        login_user(User(user["id"], user["username"], user["password"]), remember=True)
        return redirect(url_for("get_home"))

    else:
        return render_template("login.html", error="Invalid credentials!", login_page=True)


@app.route('/register', methods=['GET'])
def get_register():
    return render_template("login.html", login_page=False)


@app.route('/register', methods=['POST'])
def post_register():
    username = request.form.get("username")
    password = request.form.get("password")

    if not username or not password:
        return render_template("login.html", error="Invalid username or password!", login_page=False)

    user = db.createUser(username, sha256(password.encode()).hexdigest())
    if user:
        login_user(User(user["id"], user["username"], user["password"]), remember=True)
        return redirect(url_for("get_home"))
    else:
        return render_template("login.html", error="Error while creating user", login_page=False)


@app.route('/posts', methods=['GET'])
@login_required
def get_posts():
    user_id = request.args.get("user_id")
    search_txt = request.args.get("search")

    if not user_id:
        results = db.getAllPosts()

        if search_txt:
            search_list = [r for r in results if search(search_txt, r[1])]
            return render_template("posts.html", postlist=filterFlag(search_list))

        else:

            return render_template("posts.html", postlist=filterFlag(results))

    else:

        try:
            id = int(user_id)
        except:
            return "Error! Please enter an integer"

        results = db.getUserPosts(id)

        if results is not None:
            if search_txt:
                search_list = [r for r in results if search(search_txt, r[1])]
                return render_template("posts.html", postlist=filterFlag(search_list))

            else:

                return render_template("posts.html", postlist=filterFlag(results))

        else:
            return "Error! It was not possible to retrieve posts for the specified user"


@app.route('/insertPosts', methods=['POST'])
@login_required
def post_insertPost():
    content = request.form.get("content")
    id = current_user.id
    if not content:
        return "Error"
    else:
        db.insertPost(id, content)
    return redirect(url_for("get_posts"))


@app.route('/home', methods=['GET'])
@login_required
def get_home():
    return render_template("home.html",user_id=current_user.id)


if __name__ == '__main__':
    admin_password = open("password.txt", "r").read().strip()

    db.createUser("admin", sha256(admin_password.encode()).hexdigest())
    db.insertPost(1, "Hey, I am the admin!")
    db.insertPost(1, FLAG)

    app.run(host="0.0.0.0")
