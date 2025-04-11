def check_valid_digirom(digirom):
    x = digirom.split("-")
    if len(x) != 3:
        return False
    if x[0] != "C1":
        return False
    if len(x[1]) != 32 and len(x[2]) != 32:
        return False
    if x[1][0:8] != "4E414341":
        return False
    if x[1][8:12] != "0000" and x[2][8:12] != "0002":
        return False
    if not check_valid_checksum(digirom):
        return False
    if x[2][16:20] != "0001":
        return False
    
    return True
    
def check_valid_checksum(digirom):
    digirom = digirom.split("-")[1:]
    for packet in digirom:
        split_packet = [ packet[i:i+4] for i in range(0, len(packet[:-4]), 4) ]
        sum = 0
        for word in split_packet:
            sum += int(word, 16)
        if sum > 0xFFFF: sum = sum & 0xFFFF
        if packet[-4:] != hex(sum)[2:].upper():
            return False
    
    return True

if __name__ == "__main__":
    print("¿Te crees capaz de ganarme? ¡Nunca he perdido una pelea en mi vida!")
    print("C2-4E414341000100000011FFFF00009193-4E414341000300100000000000009195")
    digirom = input("Tu código (C1)? ")
    
    if check_valid_digirom(digirom):
        print("¡NOOOOO! ¡COMO PUDE HABER PERDIDO!")
        print("Da igual, aquí tienes lo que estabas buscando:")
        
        f = open("flag.txt", "r")
        print(f.read())
        f.close()
        
    else:
        print("¡HA! ¡Te lo dije! No eres capaz de ganarme! ¡Intentalo de nuevo!")
