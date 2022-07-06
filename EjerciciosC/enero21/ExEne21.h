/* HOJA 2 */
/* ExEne21.h */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lineas
{
    char *linea;
    struct lineas *siguiente;
} lista_lineas;

lista_lineas *cargar_f1(FILE *f);
void unir_f1_f2(FILE *f, const char *sep, lista_lineas *lptr);
void liberar(lista_lineas *lptr);