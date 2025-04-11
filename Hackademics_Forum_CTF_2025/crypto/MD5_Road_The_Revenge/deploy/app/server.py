from hashlib import md5
from random import randint
from os import urandom


with open("flag.txt", "rb") as file:
    flag = file.read()

secret = urandom(52)
bus_id = md5(secret).hexdigest()
banner = f'''
 ________________________________                          ===
 |     |     |     |     |   |   \\                        |MD5|
 |_____|_____|_____|_____|___|____\                        ===
 |{bus_id}|                         |
 |                        |  |    |                         |
 `--(0)(0)---------------(0)(0)---'                         |
'''

print("¡Ayuda a Mike a llegar a salvo a su destino! (Otra vez)")
print("Recupera el secreto en 1000 avisos.")
print(banner)

for _ in range(1000):
    try:
        obstacle = bytes.fromhex(input("Avisa de un obstáculo: "))
        print(md5(secret + obstacle + secret[:randint(0, len(secret))]).hexdigest())
    except:
        print(":(")
        exit()

secret_guessed = bytes.fromhex(input("Secreto: "))

if secret == secret_guessed:
    print("¡Has salvado a Mike!")
    print(flag)
else:
    print("¡Mike se ha estrellado! ¿De nuevo? :(")

exit()