#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INTENTOS 100
#define TOTAL_PALABRAS 100

void flush_buffers(){
    fflush(stdin);
    fflush(stdout);
}

int contar_caracteres(char *str) {
    int count = 0;
    while (*str) {
        count++;
        str++;
    }
    return count;
}

void banner() {

printf("         ░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓██████▓▒░▒▓████████▓▒░▒▓████████▓▒░ \n"); flush_buffers();
printf("         ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        \n"); flush_buffers();
printf("         ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░        ░▒▓█▓▒░   ░▒▓█▓▒░        \n"); flush_buffers();
printf("         ░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░        ░▒▓█▓▒░   ░▒▓██████▓▒░   \n"); flush_buffers();
printf("         ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░        ░▒▓█▓▒░   ░▒▓█▓▒░        \n"); flush_buffers();
printf("         ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        \n"); flush_buffers();
printf("         ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓██████▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░        \n\n"); flush_buffers();

printf(" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░      ░▒▓████████▓▒░ \n"); flush_buffers();
printf(" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░        \n"); flush_buffers();
printf(" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░        \n"); flush_buffers();
printf(" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓██████▓▒░   \n"); flush_buffers();
printf(" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░        \n"); flush_buffers();
printf(" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░        \n"); flush_buffers();
printf("  ░▒▓█████████████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓████████▓▒░ \n"); flush_buffers();

printf("\n                               La version insana de WORDLE                         \n\n"); flush_buffers();

}    

void flag() {
    FILE *file = fopen("flag", "r"); // Abrir el archivo en modo lectura
    if (file == NULL) {
        printf("No se pudo abrir el archivo flag\n"); flush_buffers();
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) { // Leer carácter por carácter
        putchar(ch); flush_buffers();
    }

    fclose(file); // Cerrar el archivo
    printf("\n"); flush_buffers();
}

int main() {

    banner();

    char nombre[100];
    char intento[100];

    const char *palabras[TOTAL_PALABRAS] = {
        "mezquita", "califato", "medina", "alcazar", "patios", "flamenco", "guitarra", "feria", "romeria", "cruces",
        "juderia", "mayo", "puente_romano", "guadalquivir", "calahorra", "molinos", "calleja", "caballo", "flores", "gitana",
        "montilla", "moriles", "vino", "aceite", "olivo", "sierra", "subbetica", "hornazo", "salmorejo", "flamenquin",
        "rabo", "naranjos", "alminar", "ermita", "sierra", "UCO", "fuensanta", "cordobes", "cordobesa", "torero",
        "museo", "medina_azahara", "sombra", "azulejos", "calesa", "cogolludo", "arruzafa", "albolafia", "sotos", "san_basilio",
        "catedral", "cristianos", "musulmanes", "mudejar", "barroco", "renacimiento", "cofradia", "semana_santa", "paso", "costalero",
        "saeta", "campanas", "caballerizas", "capilla", "naibu3", "fernandinas", "rejas", "gruta", "baños_arabes", "pozoblanco",
        "priego", "lucena", "montoro", "cabra", "zuheros", "baena", "villafranca", "pedroches", "encina", "parque_natural",
        "califa", "abderraman", "alhakem", "omeya", "azahara", "carmona", "picon", "acebuchal", "madinat", "arruzafilla",
        "portichuelo", "triana", "fuensantilla", "alcolea", "almodovar", "flag", "Hackademics", "guadalbarbo", "Aula_Ciberseguridad_y_Redes", "torrox"
    };
    

    // Pedir nombre al usuario
    printf("\nIntroduce un nombre de usuario: "); flush_buffers();
    fgets(nombre, sizeof(nombre), stdin); flush_buffers();
    // Eliminar el salto de línea si lo hay
    nombre[strcspn(nombre, "\n")] = '\0';

    int caracteres = contar_caracteres(nombre);
    printf("\n[DEBUG] Numero de caracteres: %d\n", caracteres); flush_buffers();

    srand(caracteres);  // Usa el número de caracteres como semilla

    printf("\nAdivina las 100 palabras secretas.\n"); flush_buffers();

    const char *palabra_secreta;

    // Bucle de intentos
    for (int i = 0; i < MAX_INTENTOS; i++) {
        palabra_secreta = palabras[rand() % TOTAL_PALABRAS];  // Nueva palabra en cada intento

        //printf(palabra_secreta);

        printf("Palabra %d: ", i + 1); flush_buffers();
        fgets(intento, sizeof(intento), stdin); flush_buffers();
        intento[strcspn(intento, "\n")] = '\0'; // Eliminar salto de línea

        if (strcmp(intento, palabra_secreta) == 0) {
            printf("\nCorrecto! Has adivinado la palabra.\n"); flush_buffers();
            continue;
        } else {
            printf("\nIncorrecto. Vete a jugar algo mas facil!\n"); flush_buffers();
            exit(-1);
        }
    }

    printf("Imposible que hayas ganado, seguro que hiciste trampas! Xb\n"); flush_buffers();

    flag();

    exit(0);
}
