#include "parser.h"

int parser(FILE *file)
{

    char *tok;
    char line[MaxLinea];
    char *cabecera[MaxFields] = {0};
    char *datos[MaxFields];
    int i = 0;
    char *search = ",";

    /*error al abrir archivo */
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return -1;
    }

    while (fgets(line, MaxLinea, file) != NULL)
    {

        char *tmp = strdup(line);
        // aniadimos cabecera
        if (cabecera[0] == NULL)
        {
            /*get the first token */
            tok = strtok(tmp, search);
            while (tok != NULL)
            {
                printf("%s\n", tok);
                cabecera[i] = tok;
                tok = strtok(NULL, search);
                i++;
            }
        }
        else
        {

            /* first token */
            tok = strtok(tmp, search);
            i = 0;
            while (tok != NULL)
            {

                datos[i] = tok;
                tok = strtok(NULL, search);
                i++;
            }
            cabecera[i - 1] = strtok(cabecera[i - 1], "\n");
            for (int k = 0; k < i - 1; k++)
            {

                printf("%s: %s; ", cabecera[k], datos[k]);
            }
            printf("%s: %s", cabecera[i - 1], datos[i - 1]);
        }
    }
    printf("\n");
    fclose(file);
    return 0;
}