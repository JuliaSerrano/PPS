#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct notas
{
    char *nombre;
    char *apellido;
    int notas;
    struct notas *siguiente;
} lista_notas;

int main(int argc, char *argv[])
{
    FILE *fp;
    char *tok;
    char *datos[3];
    int tam = sizeof(char) * 50 + sizeof(char) * 100 + sizeof(int);
    char line[tam];

    /* puntero primera nota*/
    lista_notas *pprimera = (struct notas *)malloc(sizeof(struct notas));
    if (pprimera == NULL)
    {
        exit(71);
    }

    lista_notas *pprimera_aux = (struct notas *)malloc(sizeof(struct notas));
    if (pprimera_aux == NULL)
    {
        exit(71);
    }

    lista_notas *lista = (struct notas *)malloc(sizeof(struct notas));
    if (lista == NULL)
    {
        exit(71);
    }

    if (argc != 2)
    {
        perror("Numero de argumentos incorrecto");
        return -1;
    }

    fp = fopen(argv[1], "r");

    /*error al abrir archivo
    if (fp == NULL)
    {
        perror("Error al abrir el archivo");
        return -1;
    }
    */

    int cont = 0;
    /* recorrer fichero */
    while (fgets(line, tam, fp) != NULL)
    {
        /*separar linea por espacios en blanco*/
        /*Nombre Apellido Nota*/
        char *tmp = strdup(line);
        int i = 0;
        tok = strtok(tmp, " ");
        while (tok != NULL)
        {
            datos[i] = tok;
            tok = strtok(NULL, " ");
            i++;
        }

        // /* 1a iteracion */
        if (cont == 0)
        {
            pprimera->nombre = malloc(50 * sizeof(char));
            if (pprimera->nombre == NULL)
            {
                exit(71);
            }

            pprimera->apellido = malloc(100 * sizeof(char));
            if (pprimera->apellido == NULL)
            {
                exit(71);
            }

            strcpy(pprimera->nombre, datos[0]);
            strcpy(pprimera->apellido, datos[1]);
            pprimera->notas = atoi(datos[2]);

            /* puntero primer elemento */
            lista = pprimera;
            cont++;
        }
        else
        {
            lista_notas *nota_aux = (struct notas *)malloc(sizeof(struct notas));
            if (nota_aux == NULL)
            {
                exit(71);
            }
            nota_aux->nombre = malloc(50 * sizeof(char));
            if (nota_aux->nombre == NULL)
            {
                exit(71);
            }
            nota_aux->apellido = malloc(100 * sizeof(char));
            if (nota_aux->apellido == NULL)
            {
                exit(71);
            }

            strcpy(nota_aux->nombre, datos[0]);
            strcpy(nota_aux->apellido, datos[1]);
            nota_aux->notas = atoi(datos[2]);

            lista->siguiente = nota_aux;
            lista = nota_aux;

            cont++;
        }
    }

    pprimera_aux->nombre = malloc(50 * sizeof(char));
    if (pprimera_aux->nombre == NULL)
    {
        exit(71);
    }

    pprimera_aux->apellido = malloc(100 * sizeof(char));
    if (pprimera_aux->apellido == NULL)
    {
        exit(71);
    }

    pprimera_aux = pprimera;

    for (int i = 0; i < cont; i++)
    {
        if ((pprimera->notas) < 5)
        {
            printf("%s %s %d \n", pprimera->nombre, pprimera->apellido, pprimera->notas);
        }
        pprimera = pprimera->siguiente;
    }
    for (int k = 0; k < cont; k++)
    {
        if ((pprimera_aux->notas) >= 5)
        {
            printf("%s %s %d \n", pprimera_aux->nombre, pprimera_aux->apellido, pprimera_aux->notas);
        }
        pprimera_aux = pprimera_aux->siguiente;
    }

    /*liberamos memoria*/
    free(pprimera);
    free(pprimera_aux);
    free(lista);

    return 0;
}
