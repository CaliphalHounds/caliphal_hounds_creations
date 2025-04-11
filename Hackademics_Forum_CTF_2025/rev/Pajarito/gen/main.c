#include <stdio.h>
#include <string.h>

#define MAGIC_KEY "awanabumbambamwiyobadiou"  

void xor_encode(const char *input, char *output) {
    size_t input_len = strlen(input);
    size_t key_len = strlen(MAGIC_KEY);

    for (size_t i = 0; i < input_len; i++) {
        char encoded_char = input[i] ^ MAGIC_KEY[i % key_len];  // XOR with key
        sprintf(output + strlen(output), "%03o ", (unsigned char)encoded_char);
    }
}

void reverse_string(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char input[512];
    char output[4096] = {0};

    printf("Cuentame tus secretos, sin miedo: ");
    fgets(input, 512, stdin);
    input[strcspn(input, "\n")] = '\0';

    xor_encode(input, output);

    reverse_string(output);

    printf("El pajarito me dijo %s\n", output);
    return 0;
}
