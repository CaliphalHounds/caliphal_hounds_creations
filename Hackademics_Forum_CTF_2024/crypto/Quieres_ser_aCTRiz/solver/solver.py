from pwn import *


r = remote("143.47.58.184", 37003)

r.recvuntil(b"Nombre: ")
r.sendline(b"Daysa")
r.recvuntil(b"Contrase\xc3\xb1a: ")
r.sendline(b"password123")
r.recvuntil(b"(SI/NO): ")
r.sendline(b"NO")
r.recvuntil(b"Petici\xc3\xb3n interceptada: ")

query = b"user=Daysa&password=password123&response=NO"
encrypted_query = bytes.fromhex(r.recvline()[:-1].decode())

padding = len(encrypted_query) - len(query)
i_byte = encrypted_query[-(padding + 1)] ^ ord("O")
new_byte = i_byte ^ ord("I")
i_byte2 = encrypted_query[-(padding + 2)] ^ ord("N")
new_byte2 = i_byte2 ^ ord("S")
new_encrypted_query = list(encrypted_query)
new_encrypted_query[-(padding + 1)] = new_byte
new_encrypted_query[-(padding + 2)] = new_byte2
new_encrypted_query = bytes(new_encrypted_query)

r.recvuntil(b"servidor: ")
r.sendline(new_encrypted_query.hex().encode())
r.interactive()