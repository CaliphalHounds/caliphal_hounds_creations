#include <stdio.h>

// gcc welcoming.c -o welcoming -no-pie -z execstack

void printTitle(char *str)
{
    puts(str);
}

void x()
{
asm("jmp %rsp");
}

int main()
{
    setbuf(stdout, 0);

    printTitle("Hey heyyyy, welcome welcome! How are you?\n");

    char buf[64];
    gets(buf);

    printf("You said: %s\n", buf);
    printf("I don't like you, bye bye!");

    return 0;
}
