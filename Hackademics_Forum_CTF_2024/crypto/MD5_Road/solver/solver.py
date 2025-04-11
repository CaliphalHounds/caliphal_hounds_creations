from pwn import *
from os import urandom
from hashlib import md5


r = remote("143.47.58.184", 37001)
r.recvuntil(b"\\                        ===\n |")
hash = r.recvuntil(b"|                         |\n |")[:-30]
r.recvuntil(b"Avisa de un obst\xc3\xa1culo: ")

while(True):
    obtacle = urandom(32)
    if md5(obtacle).hexdigest()[:5] == hash[:5].decode():
        r.sendline(obtacle.hex())
        r.interactive()