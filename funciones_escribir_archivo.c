# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"

void reiniciar_archivo(FILE* archivo, char nombre_archivo[])
{
    archivo = fopen(nombre_archivo, "w");
    fclose(archivo);
    return;
}


