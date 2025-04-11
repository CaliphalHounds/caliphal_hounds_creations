#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void function4(char * input){
    char aux[19]="\x90\xc5\x8a\xc0\xcb\xa5\xaa\xf8\xb8\xea\xdb\xd1\xa2\xa0\xab\xd5\x9a\xce";
    if(strcmp(input,aux)==0){
        printf("Enhorabuena flag encontrada\n");
    }else{
        printf("Flag invalida.... siga intentandolo\n");
    }
}

void function3(char *input, int shift) {
    int length = strlen(input);
    shift = shift % length;

    for (int i = 0; i < shift; ++i) {
        char temp = input[length - 1];
        memmove(input + 1, input, length - 1);
        input[0] = temp;
    }
    function4(input);
}


void function2(char *input) {
    size_t input_len = strlen(input);
    for (size_t i = 0; i < input_len; ++i) {
        input[i] = ~input[i];
    }
    function3(input, 5);

}


void function1(char *input, char *key) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    if(input_len!=key_len){
        return;
    }
    for (int i = 0; i < input_len; ++i) {
        input[i] = input[i] ^ key[i];
    }
    function2(input);
}


int main() {
    char input[256];
    char key[19] = "\x32\x33\x64\x33\x73\x5F\x63\x69\x38\x65\x52\x55\x63\x30\x68\x46\x49\x49";

    printf("Introduce la cadena de texto: ");
    scanf("%255s", input);

    function1(input, key);
    return 0;
}
