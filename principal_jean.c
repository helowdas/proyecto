# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"
# include "funciones_escribir_archivo.h"


void main()
{

    int fecha[3]={1,4,10};
    int tipo_donacion = 1;
    char *descripcion = "holaaa";
    int cantidad = 0;
    float valor_monetario = 5;
    int estado = 0;
    lista_donantes* list = crear_lista_donantes();
    char* nombre = "jean paul";
    int cedula = 5566;
    int telefono = 21214444;
    char* direccion = "calle 2 doña luisa";
    donante* donante = crear_donante(nombre, cedula, telefono, direccion);
    insertar_donante(list, donante);
    donacion* donacion = crear_donacion(fecha, tipo_donacion, descripcion, valor_monetario, cantidad, estado);
    insertar_donacion(list,donacion, cedula);
    char nombre_archivo[50];
    printf("escribe el nombre del archivo: ");
    scanf("%s", &nombre_archivo);
    printf("%s", nombre_archivo);
    reiniciar_archivo(nombre_archivo);
    escribir_detalle_donaciones(nombre_archivo, list);
    liberar_lista_donantes(list);
    
}   

