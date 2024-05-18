//FUNCIONES.C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define longitud_fecha 3

// NODOS PARA NECESIDADES DEL REFUGIO

typedef struct donaciones_necesidad
{
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3
    int tipo_donacion; // 1 = monetaria, 2 = material
    int estado_donacion;
    float valor_monetario;
    char *descripcion;
    struct donaciones_necesidad* siguiente_donacion;
    
}donaciones_necesidad;

typedef struct necesidad
{
    donaciones_necesidad* alimento;
    donaciones_necesidad* medicina;
    donaciones_necesidad* mantenimiento;
    donaciones_necesidad* reparaciones;
};


// NODOS PARA DONANTES Y SUS DONACIONES

typedef struct donaciones
{
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3
    int tipo_donacion; // 1 = monetaria, 2 = material, 3 = voluntariado
    char *descripcion;
    float valor_monetario;
    int estado_donacion; 
    struct donaciones* siguiente_donacion;

}donacion;

typedef struct donante
{
    char *nombre;
    int cedula;
    int telefono;
    char *direccion;
    struct donante* siguiente_donante;
    struct donante* anterior_donante;
    donacion* donaciones;

}donante;

typedef struct donantes
{
    donante *inicio;
    donante *final;

}lista_donantes;;

// NODO ARTICULOS

typedef struct articulos
{
    char *articulo;
    int cantidad;
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3

}articulo;



// FUNCIONES PARA DONANTES

//crea estructuras lista de donantes

lista_donantes* crear_lista_donantes()
{
    lista_donantes* new_list = (lista_donantes*)malloc(sizeof(lista_donantes));
    if(new_list == NULL)
    {
        printf("Erro de memoria!");
        exit(1);
    }
    
    new_list->inicio = NULL;
    new_list->final = NULL;
    
    return new_list;
}

// crear estructura donante

donante* crear_donante(char* nombre, int cedula, int telefono, char* direccion)
{
    // reservar memoria nuevo donante

    donante* new_donante = (donante*)malloc(sizeof(donante));
    if(new_donante == NULL)
    {
        printf("Erro de memoria!");
        exit(1);
    }

    new_donante->siguiente_donante = NULL;
    new_donante->anterior_donante = NULL;
    new_donante->donaciones = NULL;

    // reservar memoria nombre y asignar nombre

    new_donante->nombre = (char*)malloc(sizeof(char) * strlen(nombre));
    if(new_donante->nombre == NULL)
    {
        printf("Erro de memoria!");
        exit(1);
    }
    strcpy(new_donante->nombre, nombre);
    
    // asignar cedula

    new_donante->cedula = cedula;

    // asignar telefono

    new_donante->telefono = telefono;

    // reservar memoria direccion y asignar memoria

    new_donante->direccion = (char*)malloc(sizeof(char) * strlen(direccion));
    if(new_donante->direccion == NULL)
    {
        printf("Erro de memoria!");
        exit(1);
    }
    strcpy(new_donante->direccion, direccion);

    return new_donante;
}


// funcion que añade un donante a la lista

void insertar_donante(lista_donantes* lista, donante* new_donante)
{
    // verificar si la lista esta vacia

    if(lista->inicio == NULL)
    {
        lista->inicio = new_donante;
        lista->final = new_donante;
        return;
    }

    // ingresar el nuevo donante al final

    lista->final->siguiente_donante = new_donante;
    lista->final = new_donante;
}

