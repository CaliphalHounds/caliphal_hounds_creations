import base64

data = "431 510 670 730 430 140 070 450 410 520 640 450 310 740 640 500 270 760 601 370 320 140 550 260 700 450 370 530 370 611 350 450 150 350 540 070 310 370 660 300 010 340 360 760 510 640 140 250 250 060 350 230 710 201 070 760 521 760 640 600 700 750 540 000 110 450 750 370 220 721 650 000 120 230 070 040 700 140 000 200 500 230 660 060 210 101 330 200 200 750 040 370 410 170 670 600 600 231 050 330 610 240 250 500 500 070 660 600 520 770 121 300 130 340 460 550 300 570 160 500 220 440 531 340 500 570 540 050 720 370 150 350 420 360 540 370 110 440 060 050 001 621 400 000 600 760 050 530 610 240 270 500 230 750 030 100 500 760 270 370 420 340 440 370 401 150 140 550 720 050 760 340 130 140 560 200 500 230 010 000 100 130 710 070 110 131 230 200 501 231 670 670 021 450 200 330 500 560 670 370 620 750 010 000 100 130 710 070 230 740 060 500 220 721 670 100 600 520 450 340 500 540 631 200 321 750 260 370 420 740 410 300 200 760 401 070 000 170 650 550 510 450 740 060 230 160 250 500 500 070 660 600 520 760 160 070 530 031 060 000"

def xor_decode(octal_string, magic_key):
    octal_string = octal_string[::-1]
    octal_string = octal_string.split(" ")
    
    decoded_chars = []
    key_length = len(magic_key)

    for i, octal_value in enumerate(octal_string):
        char_code = int(octal_value, 8)  # Convert octal to integer
        original_char = chr(char_code ^ ord(magic_key[i % key_length]))  # XOR to decode
        decoded_chars.append(original_char)

    return "".join(decoded_chars)

if __name__ == "__main__":
    clavesita = "awanabumbambamwiyobadiou"  # Must match the C program   
    original = xor_decode(data, clavesita)
    
    print(original)
    
    decodificado = base64.b64decode(original)
    
    print(decodificado)
    
