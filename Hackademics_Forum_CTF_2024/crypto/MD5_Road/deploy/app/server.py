from hashlib import md5
from os import urandom


bus_id = md5(urandom(32)).digest().hex()
banner = f'''
 ________________________________                          ===
 |     |     |     |     |   |   \\                        |MD5|
 |_____|_____|_____|_____|___|____\                        ===
 |{bus_id}|                         |
 |                        |  |    |                         |
 `--(0)(0)---------------(0)(0)---'                         |
'''

print("¡Ayuda a Mike a llegar a salvo a su destino!")
print(banner)

try:
    obstacle = bytes.fromhex(input("Avisa de un obstáculo: "))
except:
    print(":(")
    exit()

if md5(obstacle).digest().hex()[:5] == bus_id[:5]:
    print("¡Obstáculo evitado!")
    
    with open("flag.txt", "rb") as file:
        flag = file.read()
    print(flag)
else:
    print("¡Mike se ha estrellado :(!")
    exit()