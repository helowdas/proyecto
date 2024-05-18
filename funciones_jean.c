//FUNCIONES.C

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define longitud_fecha 3



// NODOS PARA DONANTES Y SUS DONACIONES

typedef struct donaciones
{
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3
    int tipo_donacion; // 1 = monetaria, 2 = material, 3 = voluntariado
    char *descripcion;
    int cantidad;
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

// NODOS PARA NECESIDADES DEL REFUGIO

typedef struct donaciones_necesidad
{
    donacion* donacion;
    struct donaciones_necesidad* siguiente_donacion;
    
}donaciones_necesidad;

typedef struct necesidad
{
    donaciones_necesidad* alimento;
    donaciones_necesidad* medicina;
    donaciones_necesidad* mantenimiento;
    donaciones_necesidad* reparaciones;
}lista_necesidad;

// NODO ARTICULOS

typedef struct articulos
{
    char *articulo;
    int cantidad;
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3

}articulo;

typedef struct 
{
    articulo* inicio;

}lista_articulos;




// FUNCIONES PARA DONANTES

//crea estructuras lista de donantes

lista_donantes* crear_lista_donantes()
{
    lista_donantes* new_list = (lista_donantes*)malloc(sizeof(lista_donantes));
    if(new_list == NULL)
    {
        printf("Error de memoria!");
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
        printf("Error de memoria!");
        exit(1);
    }

    new_donante->siguiente_donante = NULL;
    new_donante->anterior_donante = NULL;
    new_donante->donaciones = NULL;

    // reservar memoria nombre y asignar nombre

    new_donante->nombre = (char*)malloc(sizeof(char) * strlen(nombre));
    if(new_donante->nombre == NULL)
    {
        printf("Error de memoria!");
        exit(1);
    }
    strcpy(new_donante->nombre, nombre);
    
    // asignar cedula

    new_donante->cedula = cedula;

    // asignar telefono

    new_donante->telefono = telefono;

    // reservar memoria direccion y asignar direccion

    new_donante->direccion = (char*)malloc(sizeof(char) * strlen(direccion));
    if(new_donante->direccion == NULL)
    {
        printf("Error de memoria!");
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

    new_donante->anterior_donante = lista->final;
    lista->final->siguiente_donante = new_donante;
    lista->final = new_donante;
}



// FUNCIONES DE USUARIO

// se buscara a los usuarios mediante su cedula

//funcion verifica si un usuario existe

int usuario_existe(lista_donantes* list, int cedula)
{
    // buscar entre la lista con ayuda de auxiliares

    donante* aux1;
    donante* aux2;

    for(aux1 = list->inicio, aux2 = list->final;  aux1 && aux2 ; aux1 = aux1->siguiente_donante, aux2 = aux2->anterior_donante)
    {
        if(aux1->cedula == cedula)
        {
            return 1;
        }
        else if(aux2->cedula == cedula)
        {
            return 1;
        }
    }

    return 0;
}


//funcion buscar usuario

donante* buscar_usuario(lista_donantes* list, int cedula)
{
    // verificar si la lista esta vacia 

    if(list->inicio == NULL)
    {
        printf("la lista de donantes esta vacia");
        return NULL; 
    }

    donante* aux1;
    donante* aux2;

    // buscar entre la lista con ayuda de auxiliares

    for(aux1 = list->inicio, aux2 = list->final;  aux1 && aux2 ; aux1 = aux1->siguiente_donante, aux2 = aux2->anterior_donante)
    {
        if(aux1->cedula == cedula)
        {
            return aux1;
        }
        else if(aux2->cedula == cedula)
        {
            return aux2;
        }
    }

    return NULL;
}


// FUNCIONES DE DONACIONES

donacion* crear_donacion(int fecha[], int tipo_donacion, char* descripcion, float valor_monetario, int cantidad)
{
    // reservar memoria donacion
    donacion* new_donacion = (donacion*)malloc(sizeof(donacion));
    if(new_donacion == NULL)
    {
        printf("Error de memoria!");
        exit(1);
    }
    new_donacion->siguiente_donacion = NULL;

    //asignar tipo de donacion
    new_donacion->tipo_donacion = tipo_donacion;

    //reservar memoria descripcion y asignar descripcion
    new_donacion->descripcion = (char*)malloc(sizeof(char) * strlen(descripcion));
    if(new_donacion->descripcion == NULL)
    {
        printf("Error de memoria!");
        exit(1);
    }
    strcpy(new_donacion->descripcion, descripcion);

    //asignar valor monetario
    new_donacion->valor_monetario = valor_monetario;

    //asignar estado de donacion
    new_donacion->estado_donacion = 1;

    //asignar fecha de donacion
    for(int i = 0; i < 3; i++)
    {
        new_donacion->fecha[i] = fecha[i];
    }

    //asignar cantidad de articulo donando

    new_donacion->cantidad = cantidad;

    return new_donacion;
}


//funcion insertar donacion
void insertar_donacion(lista_donantes* list, donacion* new_donacion, int cedula)
{
    donante* usuario = buscar_usuario(list, cedula);

    if(usuario->donaciones == NULL)
    {
        usuario->donaciones = new_donacion;
        return;
    }

    //llegar el final de la lista de donaciones para ingresarla
    donacion* aux;
    for(aux = usuario->donaciones; aux->siguiente_donacion ; aux = aux->siguiente_donacion){}
    aux->siguiente_donacion = new_donacion;
    return;
}

//FUNCIONES DE DONACIONES NECESIDAD

//funcion para crear una lista necesidad
lista_necesidad* crear_lista_necesidad()
{
    lista_necesidad* new_lista_necesidad = (lista_necesidad*)malloc(sizeof(lista_necesidad));
    if(new_lista_necesidad == NULL)
    {
        printf("error de memoria");
        exit(1);
    }
    new_lista_necesidad->alimento = NULL;
    new_lista_necesidad->mantenimiento = NULL;
    new_lista_necesidad->medicina = NULL;
    new_lista_necesidad->reparaciones = NULL;

    return new_lista_necesidad;
}

//funcion crear donacion necesidad
donaciones_necesidad* crear_donacion_necesidad(donacion* donacion)
{

}

//funcion que inserta una donacion en la lista necesidad
void insertar_donacion_necesidad(donacion* new_donacion, int necesidad)
{

}