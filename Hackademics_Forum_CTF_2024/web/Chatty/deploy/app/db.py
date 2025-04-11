import sqlite3

class DatabaseController:


    def __init__(self):
        self.db = sqlite3.connect("database.db", check_same_thread=False, isolation_level=None)
        cur = self.db.cursor()
        create_table = """CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL
        );"""
        cur.execute(create_table)

        create_table2 = """CREATE TABLE IF NOT EXISTS posts (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER,
            content TEXT NOT NULL,
            FOREIGN KEY(user_id) REFERENCES users(id)
        );"""
        cur.execute(create_table2)

        cur.close()


    def createUser(self, username, password):
        try:
            cur = self.db.cursor()
            cur.execute("INSERT INTO users VALUES(?,?,?)",
                             (None, username, password))
            self.db.commit()
            cur.close()

            return self.getUserByUsername(username)
        except Exception as e:
            print(e)
            return None

    def getUserByUsername(self, username):
        cur = self.db.cursor()
        res = cur.execute(
            "SELECT id,username,password FROM users WHERE username=?", (username,))
        user = res.fetchone()
        cur.close()

        if user:
            return {"id": user[0], "username": user[1], "password": user[2]}
        return None

    def getUserById(self, id):
        cur = self.db.cursor()
        res = cur.execute(
            "SELECT id,username,password FROM users WHERE id=?", (id,))
        user = res.fetchone()
        cur.close()
        if user:
            return {"id": user[0], "username": user[1], "password": user[2]}
        return None

    def checkPassword(self, username, password):
        cur = self.db.cursor()
        res = cur.execute("SELECT id,username,password FROM users WHERE username=? AND password=?", (username, password))
        user = res.fetchone()
        cur.close()
        if user:
            return {"id": user[0], "username": user[1], "password": user[2]}
        return None

    def insertPost(self, id, content):
        try:
            cur = self.db.cursor()
            res = cur.execute("INSERT INTO posts VALUES(?, ?, ?)", (None, id, content))
            self.db.commit()
            cur.close()
            return True

        except Exception as e:
            print(e)
            return None

    def getAllPosts(self):
        cur = self.db.cursor()
        res = cur.execute(
            "SELECT username, content FROM posts INNER JOIN users WHERE users.id=posts.user_id")
        posts = res.fetchall()
        cur.close()
        if posts:
            return posts
        return None

    def getUserPosts(self, user_id):
        cur = self.db.cursor()
        res = cur.execute(
            "SELECT username, content FROM posts INNER JOIN users WHERE users.id=posts.user_id AND users.id=?", (user_id,))
        posts = res.fetchall()
        cur.close()
        if posts:
            return posts
        return None
