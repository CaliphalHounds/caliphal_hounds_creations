Nombre del reto: `Laberinto Lógico`

Autor del reto: `kesero`

Dificultad: <font color=yellow>Fácil-Medio</font>

## Enunciado

"Hace unos días comencé mis prácticas formativas de la mano del gran maestro Juan Santos. Desde mi llegada a la empresa, no ha dejado de evaluar constantemente mis conocimientos de electrónica con pequeñas pruebas, pero la última de todas se me está resistiendo..."

## Archivos

En el reto, nos dan los siguientes archivos.

- `inputs.csv` : Contiene los estímulos de las entradas A, B, C y D.
- `logic.png` : Diagrama esquemático del circuito lógico.


## Analizando el reto

Si abrimos el archivo `logic.png` podemos ver que se trata de un diagrama esquemático realizado con transistores BJT, que a su vez cuenta con las entradas A, B, C y D y la salida output.

![esquematico](esquematico.png)

Además en el archivo `inputs.csv` nos dan los valores en binario de cada entrada.


## Solución

Para resolver el reto, tenemos que saber interpretar esquemáticos sencillos. Los transistores en este esquemático se utilizan para representar puertas lógicas, es por ello que nuestro esquemático presenta un funcionamiento en específico que sigue las reglas de las puertas lógicas.

En el siguiente [artículo](https://www.101computing.net/creating-logic-gates-using-transistors/), podemos encontrar cómo se crean puertas lógicas a través de transistores y resistencias.

Si tratamos de agrupar el funcionamiento de dichos transistores, podemos obtener que el circuito está constituido mediante el uso de puertas `AND`, `OR` y `NOT`. A su vez, dichas puertas se unen en una para representar la puerta lógica `XNOR`.

Si simplificamos el esquemático original, obtenemos el siguiente circuito lógico.

![circuito lógico](circuito_logico.png)

Una vez sabemos el funcionamiento del circuito, simplemente tenemos que calcular el `output` en base a los estímulos de las entradas que se han generado en el archivo `inputs.csv`

Para ello tenemos que implementar la siguiente lógica.

1. Leer los valores de entrada de las variables A, B, C y D.
2. Realizamos $A$ AND $B$
3. Negamos $C$ y $D$ y posteriormente calculamos $¬C$ AND $¬D$
4. En el último paso, calculamos ($A$ AND $B$) OR ($¬C$ AND $¬D$)
5. Por último, transformamos la cadena binaria a texto claro.

El script final es el siguiente.

```py
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

  # Convertir binario a ASCII (Se puede utilizar Cyberchef)
  result_string = binary_to_string(binary_output)
  print(f"[!] Texto final: \"{result_string}\"")

if __name__ == "__main__":

  main()
```
    ┌──(kesero㉿kali)-[~]
    └─$ python solver.py

    [!] Binario en bruto: 010011000110000101110011001000000111000001110101011001010111001001110100011000010111001100100000011011001111001101100111011010010110001101100001011100110010000001110000011101010110010101100100011001010110111000100000011011000110110001100101011001110110000101110010001000000110000100100000011100110110010101110010001000000110011001100001011100110110001101101001011011100110000101101110011101000110010101110011001000000111000001100001011100100110000100100000011011000110111101110011001000000111000101110101011001010010000001110010011001010110000101101100011011010110010101101110011101000110010100100000011100110110000101100010011001010110111000100000011000010111000001110010011001010110001101101001011000010111001001101100011000010111001100101100001000000110100001100110011000110111010001100110011110110011010001101100011001110111010101101110001101000101111101110110001100110111101001011111010010000011010001110011010111110011001101110011011000110101010101100011011010000011010001100100001100000101111101110011001100000110001001110010001100110101111101011000010011100011000001010010001111110011111101111101

    [!] Texto final: "Las puertas lógicas pueden llegar a ser fascinantes para los que realmente saben apreciarlas, hfctf{4lgun4_v3z_H4s_3scUch4d0_s0br3_XN0R??}"



## Flag

`hfctf{4lgun4_v3z_H4s_3scUch4d0_s0br3_XN0R??}`