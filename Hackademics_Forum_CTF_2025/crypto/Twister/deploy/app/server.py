from random import getrandbits


with open("flag.txt", "rb") as file:
    flag = file.read()

def banner():
    colors = {
        'R': '\033[41m',
        'G': '\033[42m',
        'B': '\033[46m',
        'Y': '\033[43m',
        'RESET': '\033[0m'
    }

    board = [
        ['R', 'B', 'Y', 'G', 'R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G', 'R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G','R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G', 'R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G', 'R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G', 'R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G','R', 'B', 'Y', 'G'],
        ['R', 'B', 'Y', 'G', 'R', 'B', 'Y', 'G']
    ]

    print("Bienvenidos al Twister 2.0. Para superarlo tienes que ser capaz de ver el futuro...")
    print("+---+---+---+---+---+---+---+---+")
    for row in board:
        for cell in row:
            print(f"|{colors[cell]}   {colors['RESET']}", end="")
        print("|\n+---+---+---+---+---+---+---+---+")

def rebase(n):
    if n < 64:
        return [n]
    else:
        return [n % 64] + rebase(n//64)


banner()

spins = 4500
streak = 0

n = getrandbits(32)
l = rebase(n) + [n.bit_length()]

for spin in range(spins):
    print(f"\n======= Ronda {spin} =======")
    if l == []:
        n = getrandbits(32)
        l = rebase(n) + [n.bit_length()]

    try:
        coordinate = input("¿Qué color va a salir? Formato: x,y. ").split(",")
        x, y = int(coordinate[0]), int(coordinate[1])
    except:
        print(":(")
        exit()
    
    n = l.pop()
    real_x = n // 8
    real_y = n % 8

    if [x, y] == [real_x, real_y]:
        print("¡Correcto!")
        streak += 1
    else:
        print("¡Sigue intentándolo!")
        streak = 0
    
    print(f"Resultado: [{real_x}, {real_y}]")
    
    if streak == 100:
        print("¿Cuál es el siguiente número de la bonoloto?")
        print(flag)