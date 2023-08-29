/* 本文件记录C语言常用宏定义技巧及常用函数 */
#include <stdio.h>

/* functionName()
 *  Functionality: description...
 *  Arguments: arguments...
 *  Return: possibleReturnValues
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/* int main(int argc, char *argv[])
 *  Functionality: description...
 *  Arguments: arguments...
 *  Return: possibleReturnValues
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
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