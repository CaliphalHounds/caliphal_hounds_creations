#!/usr/bin/env python3
from pwn import *
import ctypes
import sys

libc = ctypes.CDLL("libc.so.6")

if len(sys.argv) == 1:
    p = remote('localhost', 33334)
else:
    p = process('./main')

libc.srand(6)

# RECEIVE HEADER
for i in range(0, 18):
    data = p.recvline().decode().rstrip()
    print(data)

data = p.recvuntil(b"usuario:")
print(data)
p.sendline("naibu3")

data = p.recvline()
print(data)
data = p.recvline()
print(data)
data = p.recvline()
print(data)
data = p.recvline()
print(data)


table = ["mezquita", "califato", "medina", "alcazar", "patios", "flamenco", "guitarra", "feria", "romeria", "cruces",
        "juderia", "mayo", "puente_romano", "guadalquivir", "calahorra", "molinos", "calleja", "caballo", "flores", "gitana",
        "montilla", "moriles", "vino", "aceite", "olivo", "sierra", "subbetica", "hornazo", "salmorejo", "flamenquin",
        "rabo", "naranjos", "alminar", "ermita", "sierra", "UCO", "fuensanta", "cordobes", "cordobesa", "torero",
        "museo", "medina_azahara", "sombra", "azulejos", "calesa", "cogolludo", "arruzafa", "albolafia", "sotos", "san_basilio",
        "catedral", "cristianos", "musulmanes", "mudejar", "barroco", "renacimiento", "cofradia", "semana_santa", "paso", "costalero",
        "saeta", "campanas", "caballerizas", "capilla", "naibu3", "fernandinas", "rejas", "gruta", "baños_arabes", "pozoblanco",
        "priego", "lucena", "montoro", "cabra", "zuheros", "baena", "villafranca", "pedroches", "encina", "parque_natural",
        "califa", "abderraman", "alhakem", "omeya", "azahara", "carmona", "picon", "acebuchal", "madinat", "arruzafilla",
        "portichuelo", "triana", "fuensantilla", "alcolea", "almodovar", "flag", "Hackademics", "guadalbarbo", "Aula_Ciberseguridad_y_Redes", "torrox"] # Words

for i in range(100):
    r = libc.rand()
    word = table[r % 100]
    log.info(word)

    data = p.recvuntil(b': ').decode()
    print(data + word)
    p.sendline(word.encode())
    response = p.recvline().decode().rstrip()
    print(response)

for _ in range(3):
    data = p.recvline().decode().rstrip()
    print(data)
