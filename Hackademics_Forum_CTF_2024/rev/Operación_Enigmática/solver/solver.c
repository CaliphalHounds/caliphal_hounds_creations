#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void XOR2(char *input, int n2) {
    int input_len = strlen(input);
    for (int i = 0; i < input_len; ++i) {
        input[i] = input[i] ^n2;
    }
}

void XOR1(char *input, int n1) {
    int input_len = strlen(input);
    for (int i = 0; i < input_len; ++i) {
        input[i] = input[i] ^ n1;
    }
    XOR2(input,4);
}

int main() {
    char flag_encoded[]="\x6f\x61\x64\x73\x61\x7c\x5f\x64\x75\x36\x77\x73\x37\x60\x75\x33\x61\x36\x66\x58\x4a\x66\x73\x34\x6a\x33\x73\x36\x64\x66\x26\x7a";
    XOR1(flag_encoded, 3);
    printf("%s\n", flag_encoded);
}
