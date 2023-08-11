#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of command-line arguments: %d\n", argc);

    printf("Command-line arguments:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}

// $ ./program arg1 arg2 arg3
// Number of command-line arguments: 4
// ./program
// arg1
// arg2
// arg3