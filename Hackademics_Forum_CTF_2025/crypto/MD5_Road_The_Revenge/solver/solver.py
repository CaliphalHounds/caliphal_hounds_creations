from pwn import *
import HashTools


r = process(['python3', 'server.py'])
r.recvuntil(b"\\                        ===\n |")
signature = r.recvuntil(b"|                         |\n |")[:-30]

hashes = []
for _ in range(1000):
    r.recvuntil(b"Avisa de un obst\xc3\xa1culo: ")
    r.sendline(b"80000000a001000000000000")
    hash = r.recvline().strip()
    if hash not in hashes:
        hashes.append(hash)

secret = b""
for _ in range(52):
    for i in range(256):
        hashtool = HashTools.new("md5")
        _, hash = hashtool.extension(secret_length=52, original_data=b"", append_data=secret + bytes([i]), signature=signature.decode())
        if hash.encode() in hashes:
            secret += bytes([i])
            print(secret)
            break

r.recvuntil(b"Secreto: ")
r.sendline(secret.hex())
r.interactive()
            
