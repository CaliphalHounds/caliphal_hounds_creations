from pwn import *
from Crypto.Util.number import long_to_bytes


r = remote("143.47.58.184", 37002)

r.recvuntil(b"e:")
e = int(r.recvuntil(b"n:")[:-3])
n = int(r.recvline())
r.recvuntil(b">")

r.sendline(b"2")
r.recvuntil(b"Flag cifrada: ")
c = int(r.recvline())

k = 2
c_prime = pow(k, e, n) * c % n

r.sendline(b"1")
r.sendline(str(c_prime).encode())
r.recvuntil(b"Tu texto claro: ")
m_prime = int(r.recvline())


print(long_to_bytes(m_prime * pow(k, -1, n) % n))