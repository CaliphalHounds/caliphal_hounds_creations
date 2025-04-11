from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from os import urandom
from hashlib import sha1


BLOCK_SIZE = 16
key = urandom(BLOCK_SIZE)
nonce = urandom(BLOCK_SIZE - 1)

def encrypt(key, input, nonce):
    hash = sha1()
    hash.update(str(key).encode('ascii'))
    key = hash.digest()[:BLOCK_SIZE]
    cipher = AES.new(key, AES.MODE_CTR, nonce=nonce)
    return cipher.encrypt(pad(input, BLOCK_SIZE))

def decrypt(key, input, nonce):
    hash = sha1()
    hash.update(str(key).encode('ascii'))
    key = hash.digest()[:BLOCK_SIZE]
    cipher = AES.new(key, AES.MODE_CTR, nonce=nonce)
    return unpad(cipher.decrypt(input), BLOCK_SIZE)


print("=== Registro para el casting ===")
user = input("Nombre: ")
password = input("Contraseña: ")
response = input("¿Quieres ser actriz? (SI/NO): ")

if response == "SI":
    print("¡Eso lo decidimos nosotros!")
    exit()
elif response == "NO":
    query = b"user=" + user.encode() + b"&password=" + password.encode() + b"&response=NO"
else:
    print("Error")
    exit()

encrypted_query = encrypt(key, query, nonce)
print("Petición interceptada: " + encrypted_query.hex())

new_query = input("Petición a enviar al servidor: ")
try:
    query = decrypt(key, bytes.fromhex(new_query), nonce)
except:
    print("Error")
    exit()

if query[-2:] == b"SI":
    with open("flag.txt", "rb") as file:
        flag = file.read()
    print(flag)
else:
    print("No tienes madera de actriz")
    exit()