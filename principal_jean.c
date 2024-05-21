# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"

void main()
{
    int fecha[3]={1,4,10};
    int tipo_donacion = 2;
    char *descripcion = "holaaa";
    int cantidad = 0;
    float valor_monetario = 5;
    int estado = 0;

    donacion* donacion = crear_donacion(fecha, tipo_donacion, descripcion, valor_monetario, cantidad, estado);
    for(int i = 0; i < 3; i++)
        printf("%d\n", donacion->fecha[i]);
    printf("tipo donacion: %d\n", donacion->tipo_donacion);
    printf("tipo descripcion: %s\n", donacion->descripcion);
    printf("tipo cantidad: %d\n", donacion->cantidad);
    printf("tipo valor monetario: %.2f\n", donacion->valor_monetario);
    printf("estado donacion: ");
    printf(donacion->estado_donacion?"disponible\n":"no disponible\n");
}  

