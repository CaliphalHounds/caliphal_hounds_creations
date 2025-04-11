#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char key[] = "\x32\x33\x64\x33\x73\x5F\x63\x69\x38\x65\x52\x55\x63\x30\x68\x46\x49\x49";
void XOR(char *input, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);
    for (int i = 0; i < input_len; ++i) {
        input[i] = input[i] ^ key[i];
    }
}

void NOT(char *input) {
    size_t input_len = strlen(input);
    for (size_t i = 0; i < input_len; ++i) {
        input[i] = ~input[i];
    }
    XOR(input, key);
}

void ROL(char *input, int shift) {
    int length = strlen(input);
    shift = shift % length;

    for (int i = 0; i < shift; ++i) {
        char temp = input[0];
        memmove(input, input + 1, length - 1);
        input[length - 1] = temp;
    }
    NOT(input);
}


int main() {
    char flag_encoded[]="\x90\xc5\x8a\xc0\xcb\xa5\xaa\xf8\xb8\xea\xdb\xd1\xa2\xa0\xab\xd5\x9a\xce";
    ROL(flag_encoded, 5);
    printf("%s\n", flag_encoded);
}

//Compilación con Os, enmascara la key
//Compilación de finstrument-functions, añade variables de retorno
//Compilación de O3, enmascara aun mas las cadenas