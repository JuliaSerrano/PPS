#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExEne21.h"

/** Cargar líneas del primer fichero en memoria dinámica
 * Se valorará específicamente la claridad y estructura del código
 */
lista_lineas *cargar_f1(FILE *f)
{
    lista_lineas *head = NULL, *aux = NULL, *nuevo = NULL;
    char line[2049];
    int len;
    while (fgets(line, 2049, f))
    {
        len = strlen(line);

        if (line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        nuevo = (lista_lineas *)malloc(sizeof(lista_lineas));
        if (nuevo == NULL)
        {
            fprintf(stderr, "ERROR: No se pudo asignar memoria dinámica \n");
            return NULL;
        }
        nuevo->linea = strdup(line);
        if (nuevo->linea == NULL)
        {
            fprintf(stderr, "ERROR: No se pudo asignar memoria dinámica \n");
            return NULL;
        }
        nuevo->siguiente = NULL;
        if (head == NULL)
        {
            head = nuevo;
            aux = head;
        }
        else
        {
            aux->siguiente = nuevo;
            aux = aux->siguiente;
        }
    }
    return head;
}