import csv

# Binario a Ascii
def binary_to_string(binary_string):
    
    characters = []
    
    for i in range(0, len(binary_string), 8):
        byte = binary_string[i:i+8]
        if len(byte) == 8:
            decimal_value = int(byte, 2)
            characters.append(chr(decimal_value))
    
    result_string = ''.join(characters)
    return result_string

def logic():

    results = []
    
    with open('inputs.csv', mode='r') as infile:
        csvreader = csv.reader(infile)
        next(csvreader)  # Omitir la cabecera

        # Leer entradas
        for row in csvreader:
            input1 = int(row[0])
            input2 = int(row[1])
            input3 = int(row[2])
            input4 = int(row[3])

            # A AND B
            and_output1 = input1 & input2
            
            # Negación de C y D
            not_input3 = not input3  
            not_input4 = not input4 

            # ¬C AND ¬D
            and_output2 = not_input3 & not_input4
            
            # C_D OR A_B 
            final_output = and_output1 | and_output2
            
            results.append(str(final_output))

    return ''.join(results)

def main():

  binary_output = logic()
  print(f"[!] Binario en bruto: {binary_output}\n")

  # Convertir binario a ascii (Se puede utilizar Cyberchef)
  result_string = binary_to_string(binary_output)
  print(f"[!] Texto final: \"{result_string}\"")

if __name__ == "__main__":

  main()