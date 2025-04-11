from Crypto.Util.number import getStrongPrime, bytes_to_long


with open("flag.txt", "rb") as file:
    flag = file.read()

e = 3
p = getStrongPrime(1024, e=e)
q = getStrongPrime(1024, e=e)
n = p*q

phi = (p - 1)*(q - 1)
phi_enc = pow(phi, e, n)
pplusq_enc = pow(p + q, e, n)
ct = pow(bytes_to_long(flag), e, n)

assert pow(bytes_to_long(flag), e) > n

with open("output.txt", "w") as file:
    file.write(f"e = {str(e)}\n")
    file.write(f"n = {str(n)}\n")
    file.write(f"phi_enc = {str(phi_enc)}\n")
    file.write(f"pplusq_enc = {str(pplusq_enc)}\n")
    file.write(f"ct = {str(ct)}\n")