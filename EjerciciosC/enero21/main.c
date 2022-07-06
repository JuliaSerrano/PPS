/* HOJA 1*/

#include "ExEne21.h"

lista_lineas *lista = NULL;

int main(int argc, char const *argv[])
{
    FILE *fichero1;
    FILE *fichero2;

    /* Primera parte: procesado de args*/
    if (argc != 4)
    {
        fprintf(stderr, "ERROR: Número de argumentos incorrecto\n");
        exit(64);
    }

    fichero1 = fopen(argv[1], "r");
    if (fichero1 == NULL)
    {

        fprintf(stderr, "ERROR: No se ha podido abrir el archivo %s\n", argv[1]);
        exit(74);
    }

    fichero2 = fopen(argv[3], "r");
    if (fichero2 == NULL)
    {
        fprintf(stderr, "ERROR: No se ha podido abrir el archivo%s \n", argv[3]);
        exit(74);
    }

    /* Segunda parte: carga en memdin */
    lista = cargar_f1(fichero1);
    if (lista == NULL)
    {
        exit(66);
    }

    /* Tercera parte: unir líneas fich1 y fich2 */
    unir_f1_f2(fichero2, argv[2], lista);

    /* Cuarta parte: salida ordenada */
    liberar(lista);
    fclose(fichero1);
    fclose(fichero2);
    exit(0);
}
/**
 * Liberar memoria dinámica
 */
void liberar(lista_lineas *lptr)
{
    lista_lineas *aux = lptr, *aux2;
    while (aux != NULL)
    {
        aux2 = aux;
        aux = aux->siguiente;
        free(aux2->linea);
        free(aux2);
    }
}