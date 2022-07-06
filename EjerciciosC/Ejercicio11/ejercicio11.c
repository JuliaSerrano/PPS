
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long int filas;
    long int columnas;

    if (argc != 3)
    {
        perror("Error en el numero de argumentos pasado");
        return -1;
    }
    filas = (long int)atoi(argv[1]);
    columnas = (long int)atoi(argv[2]);
    long int *pmatriz[filas];

    /* guardar espacio para matriz */
    for (long int i = 0; i < filas; i++)
    {
        pmatriz[i] = (long int *)malloc(columnas * sizeof(long int));
        if (pmatriz[i] == NULL)
        {
            /* error asignacion memoria*/
            exit(71);
        }
    }

    /* creacion matriz */
    for (long int i = 0; i < filas; i++)
    {
        for (long int j = 0; j < columnas; j++)
        {
            /* primera fila =1 */
            if (i == 0)
            {
                pmatriz[i][j] = 1;
            }
            /* primera columna */
            else if (j == 0)
            {
                pmatriz[i][j] = 1;
            }
            else
            {
                pmatriz[i][j] = pmatriz[i][j - 1] + pmatriz[i - 1][j];
            }
        }
    }

    /* print */
    for (long int i = 0; i < filas; i++)
    {
        for (long int j = 0; j < columnas; j++)
        {
            printf("%li\t", pmatriz[i][j]);
        }
        printf("\n");
    }

    /* liberar espacio*/
    for (long int i = 0; i < filas; i++)
    {
        free(pmatriz[i]);
    }

    return 0;
}
