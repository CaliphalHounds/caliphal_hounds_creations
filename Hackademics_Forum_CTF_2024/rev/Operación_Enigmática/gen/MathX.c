#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float sumar(float x, float y) {
    return x + y;
}

float restar(float x, float y) {
    return x - y;
}

float multiplicar(float x, float y) {
    return x * y;
}

float dividir(float x, float y) {
    if (y != 0) {
        return x / y;
    } else {
        printf("Error: No es posible dividir por cero.\n");
        return 0.0;
    }
}

int function8(char * input){
    char new[]="\x6f\x61\x64\x73\x61\x7c\x5f\x64\x75\x36\x77\x73\x37\x60\x75\x33\x61\x36\x66\x58\x4a\x66\x73\x34\x6a\x33\x73\x36\x64\x66\x26\x7a";
    char cadena_texto_hex[1024];  
    sscanf(new, "%s", cadena_texto_hex);

    if(strcmp(input,new)==0){
        printf("Enhorabuena flag encontrada\n");
        return 0;
    }else{
        printf("Flag invalida.... siga intentandolo\n");
        return 1;
    }
}
    
void function7(char *input, int n2){
    int len=strlen(input);
    for(int i=0; i<len; i++){
        input[i]=input[i]^n2;
    }
    function8(input);
}

void function6(char *input, int n1, int n2){
    int len=strlen(input);
    for(int i=0; i<len; i++){
        input[i]=input[i]^n1;
    }
    if(n2==3){
        function7(input,n2);
    }else{
        return;
    }  
}

void function5(float num1, float num2){
    char input[256];
    int n1=(int)num1;
    int n2=(int)num2;
    int len=strlen(input);
    scanf("%255s", input);
    if(n1==n2){
        return;
    }else{
        if(n1==4){
            function6(input,n1,n2);
        }else{
            return;
        }
    }
}


int main() {
    char expresion[20];
    float num1, num2, resultado;
    char exit;
    char operacion;

    while(1){
        printf("\nIngresa una expresión matemática:\n");
        printf(".......................................\n");
        printf("Sumar\n");
        printf("Restar\n");
        printf("Multiplicar\n");
        printf("Dividir\n");
        printf("Pulse . para salir\n");
        printf(".......................................\n");

        fgets(expresion, sizeof(expresion), stdin);

        if(sscanf(expresion,"%c", &exit)){
            if (exit=='.'){
                printf("\nSaliendo......\n");
                return 0;
            }
        }

        if (sscanf(expresion, "%f%c%f", &num1, &operacion, &num2) == 3) {
            switch (operacion) {
                case '+':
                    resultado = sumar(num1, num2);
                    printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
                    break;
                case '-':
                    resultado = restar(num1, num2);
                    printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
                    break;
                case '*':
                    resultado = multiplicar(num1, num2);
                    printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
                    break;
                case '/':
                    resultado = dividir(num1, num2);
                    break;
                case '?':
                    function5(num1,num2);
                    break;
                case 5:
                    return 0;
                    break;
                default:
                    printf("Operación no válida.\n");
                    return 1;
            }
        } else {
            printf("Expresión no válida.\n");
            return 1;
        }
    }
    return 0;
}
