from Crypto.Util.number import getPrime, bytes_to_long


p = getPrime(1024)
q = getPrime(1024)
n = p*q
phi = (p - 1)*(q - 1)

e = 65537
d = pow(e, -1, phi)

with open("flag.txt", "rb") as file:
    flag = bytes_to_long(file.read())

encrypted_flag = pow(flag, e, n)


print("== Clave pública ==")
print("e:" + str(e))
print("n:" + str(n))
print("\n")

while True:
    print("|1| - Descifrar")
    print("|2| - Conseguir flag")
    print("|0| - Salir")
    choice = input("> ")

    if choice == "0":
        exit()

    elif choice == "1":
        try:
            c = int(input("Texto cifrado: "))
        except:
            print("Error")
            exit()
        m = pow(c, d, n)
        
        if c == encrypted_flag or c == pow(encrypted_flag, -1, n):
            print("¡Tramposo!")
            exit()

        print("Tu texto claro: " + str(m))

    elif choice == "2":
        print("Flag cifrada: " + str(encrypted_flag))

    else:
        print("Error")
        exit()
    print("\n")