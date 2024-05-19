
#ifndef FUNCIONES_H
#define FUNCIONES_H
# include "funciones_jean.c"
# define longitud_fecha 3

// FUNCIONES PARA DONANTES

//crea estructuras lista de donantes

lista_donantes* crear_lista_donantes();

// crear estructura donante

donante* crear_donante(char* nombre, int cedula, int telefono, char* direccion);

// funcion que añade un donante a la lista

void insertar_donante(lista_donantes* lista, donante* new_donante);

// FUNCIONES DE USUARIO

// se buscara a los usuarios mediante su cedula

//funcion verifica si un usuario existe
int usuario_existe(lista_donantes* list, int cedula);

//funcion buscar usuario

donante* buscar_usuario(lista_donantes* list, int cedula);


// FUNCIONES DE DONACIONES

// funcion que crea una donacion
donacion* crear_donacion(int fecha[], int tipo_donacion, char* descripcion, float valor_monetario, int cantidad);

//funcion insertar donacion
void insertar_donacion(lista_donantes* list, donacion* new_donacion, int cedula);


//FUNCIONES DE DONACIONES NECESIDAD

//funcion para crear una lista necesidad
lista_necesidad* crear_lista_necesidad();

//funcion crear donacion necesidad
donaciones_necesidad* crear_donacion_necesidad(donacion* donacion);

//funcion que inserta una donacion en la lista necesidad deseada
void insertar_donacion_necesidad(lista_necesidad* list, donaciones_necesidad* new_donacion, int necesidad);


// FUNCIONES ARTICULOS

//funcion que crea una lista articulos
lista_articulos* crear_lista_articulos();

//funcion que crea una estructura articulo
articulos* crear_articulo(char* articulo, int cantidad, int fecha[]);

//funcion ingresa un articulo en la lista articulos
void ingresa_articulo(lista_articulos* list, articulos* new_articulo);

#endif // FUNCIONES_H