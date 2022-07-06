#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExEne21.h"

/**
 * Unir líneas del segundo fichero e imprimir
 */
void unir_f1_f2(FILE *f, const char *sep, lista_lineas *lptr)
{
    char line[2049];
    lista_lineas *aux;
    aux = lptr;
    while (fgets(line, 2049, f) && aux != NULL)
    {
        fprintf(stdout, "%s%s%s", aux->linea, sep, line);
        aux = aux->siguiente;
    }
    if (feof(f) && aux != NULL)
    {
        fprintf(stderr, "STOP: Fichero 2 tiene menos lineas \n");
    }
    if (!feof(f) && aux == NULL)
    {
        fprintf(stderr, "STOP: Fichero 1 tiene menos lineas \n");
    }
}