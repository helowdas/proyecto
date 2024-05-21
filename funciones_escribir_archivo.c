# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"

void reiniciar_archivo(FILE* archivo, char nombre_archivo[])
{
    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }
    fclose(archivo);
    return;
}

void imprimir_detalle_donaciones(FILE* archivo, char nombre_archivo[])
{
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("DETALLE DONACIONES", archivo);
}


