from pwn import *
from randcrack import RandCrack


def rebase(n):
    if n < 64:
        return [n]
    else:
        return [n % 64] + rebase(n//64)


r = process(['python3', 'server.py'])

l = []
states = []

rc = RandCrack()

while len(states) != 624:
    r.sendlineafter(b"Formato: x,y. ", "0,0")
    print(r.recvline())
    r.recvline()
    coordinates = eval(r.recvline().replace(b"Resultado:", b""))

    l.append(coordinates[0] * 8 + coordinates[1])

    state = sum([el * 64**i for i, el in enumerate(l[::-1][:-1])])
    
    if state.bit_length() == l[0]:
        states.append(state)
        rc.submit(state)
        l = []
        state = 0

for _ in range(100):
    if l == []:
        next_state = rc.predict_getrandbits(32)
        l = rebase(next_state) + [next_state.bit_length()]

    n = l.pop()
    r.sendlineafter(b"Formato: x,y. ", str(n // 8) + "," + str(n % 8))
    
r.interactive()