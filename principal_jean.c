# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"
# include "funciones_escribir_archivo.h"

void main()
{
    int fecha[3]={1,4,10};
    int tipo_donacion = 2;
    char *descripcion = "holaaa";
    int cantidad = 0;
    float valor_monetario = 5;
    int estado = 0;

    donacion* donacion = crear_donacion(fecha, tipo_donacion, descripcion, valor_monetario, cantidad, estado);
   

