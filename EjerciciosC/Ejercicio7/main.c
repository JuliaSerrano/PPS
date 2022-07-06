#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{

    // se pasa fichero como argumento
    if (argc >= 2)
    {
        parser(fopen(argv[1], "r"));
    }
    // se pasa fichero como stdin
    else if (argc == 1)
    {

        perror("df");
    }
    else
    {
        perror("Error numero incorrecto de argumentos");
        return -1;
    }

    return 0;
}
