
#ifndef FUNCIONES_H
#define FUNCIONES_H
# include "funciones_manejo_estructuras.c"
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

// funcion que crea una nodo_donacion
nodo_donacion* crear_donacion(int fecha[], int tipo_donacion, char* descripcion, float valor_monetario, int cantidad, int estado);

//funcion insertar nodo_donacion
void insertar_donacion(lista_donantes* list, nodo_donacion* new_donacion, int cedula);


//FUNCIONES DE DONACIONES NECESIDAD

//funcion para crear una lista necesidad
lista_necesidad* crear_lista_necesidad();

//funcion crear nodo_donacion necesidad
donaciones_necesidad* crear_donacion_necesidad(nodo_donacion* nodo_donacion);

//funcion que inserta una nodo_donacion en la lista necesidad deseada
void insertar_donacion_necesidad(lista_necesidad* list, donaciones_necesidad* new_donacion, int necesidad);


// FUNCIONES ARTICULOS

//funcion que crea una lista articulos
lista_articulos* crear_lista_articulos();

//funcion que crea una estructura articulo
articulos* crear_articulo(char* articulo, int cantidad, int fecha[]);

//funcion ingresa un articulo en la lista articulos
void ingresa_articulo(lista_articulos* list, articulos* new_articulo);

// FUNCIONES CONTAR

int contar_donaciones(lista_donantes* list, int cedula);

// FUNCIONES LIBERAR MEMORIA

// liberar los articulos
void liberar_lista_articulos(lista_articulos* lista_articulos);

// liberar las necesidades
void liberar_lista_necesidad(lista_necesidad* lista_necesidad);

//funcion libera donantes
void liberar_lista_donantes(lista_donantes* lista_donantes);

//funcion liberar las listas
void liberar_memoria(lista_articulos* lista_articulos, lista_donantes* lista_donantes, lista_necesidad* lista_necesidad);

#endif // FUNCIONES_H