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
    int asignacion = 3;
    lista_donantes* list_donantes = crear_lista_donantes();
    lista_articulos* list_articulos = crear_lista_articulos();
    lista_necesidad* lista_necesidad = crear_lista_necesidad();
    char* nombre = "jean paul";
    int cedula = 5566;
    int telefono = 21214444;
    char* direccion = "calle 2 doña luisa";
    donante* donante = crear_donante(nombre, cedula, telefono, direccion);
    insertar_donante(list_donantes, donante);
    nodo_donacion* nodo_donaciones = crear_donacion(fecha, tipo_donacion, descripcion, valor_monetario, cantidad, estado, asignacion);
    insertar_donacion(list_donantes,nodo_donaciones, cedula);
    cantidad = 2;
    articulo* new_articulo = crear_articulo(nombre, cantidad, fecha);
    donaciones_necesidad* new_donacion_necesidad = crear_donacion_necesidad(nodo_donaciones);
    donaciones_necesidad* new_donacion_necesidad2 = crear_donacion_necesidad(nodo_donaciones);
    donaciones_necesidad* new_donacion_necesidad3 = crear_donacion_necesidad(nodo_donaciones);
    donaciones_necesidad* new_donacion_necesidad4 = crear_donacion_necesidad(nodo_donaciones);
    insertar_donacion_necesidad(lista_necesidad, new_donacion_necesidad, 1);
    insertar_donacion_necesidad(lista_necesidad, new_donacion_necesidad2, 2);
    //insertar_donacion_necesidad(lista_necesidad, new_donacion_necesidad3, 3);
    insertar_donacion_necesidad(lista_necesidad, new_donacion_necesidad4, 4);
    ingresa_articulo(list_articulos, new_articulo);
    char nombre_archivo[50];
    printf("escribe el nombre del archivo: ");
    scanf("%s", &nombre_archivo);
    printf("%s", nombre_archivo);
    reiniciar_archivo(nombre_archivo);
    escribir_detalle_donaciones(nombre_archivo, list_donantes);
    escribir_asignacion_donaciones(nombre_archivo, lista_necesidad);
    escribir_detalle_articulos(nombre_archivo, list_articulos);
    escribir_detalles_donantes(nombre_archivo, list_donantes);
    liberar_memoria(list_articulos, list_donantes, lista_necesidad);
    
}   

