from Crypto.Util.number import getPrime, bytes_to_long


with open("flag.txt", "rb") as file:
    flag = file.read()

e = 65537
p = getPrime(1024)
q = getPrime(1024)
n = p*q

phi = (p - 1)*(q - 1)
leak = p*phi
ct = pow(bytes_to_long(flag), e, n)

with open("output.txt", "w") as file:
    file.write(f"e = {str(e)}\n")
    file.write(f"n = {str(n)}\n")
    file.write(f"ct = {str(ct)}\n")
    file.write(f"leak = {str(leak)}\n")