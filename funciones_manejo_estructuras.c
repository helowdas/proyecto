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

}nodo_donacion;

typedef struct donantes
{
    char *nombre;
    int cedula;
    int telefono;
    char *direccion;
    struct donantes* siguiente_donante;
    struct donantes* anterior_donante;
    nodo_donacion* donaciones;

}donante;

typedef struct
{
    donante *inicio;
    donante *final;

}lista_donantes;

// NODOS PARA NECESIDADES DEL REFUGIO

typedef struct donaciones_necesidades
{
    nodo_donacion* nodo_donacion;
    struct donaciones_necesidades* siguiente_donacion;
    
}donaciones_necesidad;

typedef struct 
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
    struct articulos* siguiente_articulo;

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

//funcion que crea una nodo_donacion
nodo_donacion* crear_donacion(int fecha[], int tipo_donacion, char* descripcion, float valor_monetario, int cantidad, int estado)
{
    // reservar memoria nodo_donacion
    nodo_donacion* new_donacion = (nodo_donacion*)malloc(sizeof(nodo_donacion));
    if(new_donacion == NULL)
    {
        printf("Error de memoria!");
        exit(1);
    }
    new_donacion->siguiente_donacion = NULL;

    //asignar tipo de nodo_donacion
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

    //asignar estado de nodo_donacion
    new_donacion->estado_donacion = estado;

    //asignar fecha de nodo_donacion
    for(int i = 0; i < 3; i++)
    {
        new_donacion->fecha[i] = fecha[i];
    }

    //asignar cantidad de articulo donando

    new_donacion->cantidad = cantidad;

    return new_donacion;
}


//funcion insertar nodo_donacion
void insertar_donacion(lista_donantes* list, nodo_donacion* new_donacion, int cedula)
{
    donante* usuario = buscar_usuario(list, cedula);

    if(usuario->donaciones == NULL)
    {
        usuario->donaciones = new_donacion;
        return;
    }

    //llegar el final de la lista de donaciones para ingresarla
    nodo_donacion* aux;
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

//funcion crear nodo_donacion necesidad
donaciones_necesidad* crear_donacion_necesidad(nodo_donacion* nodo_donacion)
{
    donaciones_necesidad* new_donacion_necesidad = (donaciones_necesidad*)malloc(sizeof(donaciones_necesidad));
    if(new_donacion_necesidad == NULL)
    {
        printf("error de memoria");
        exit(1);
    }
    new_donacion_necesidad->nodo_donacion = nodo_donacion;
    new_donacion_necesidad->siguiente_donacion = NULL;
    return new_donacion_necesidad;
}

//funcion que inserta una nodo_donacion en la lista necesidad deseada
void insertar_donacion_necesidad(lista_necesidad* list, donaciones_necesidad* new_donacion, int necesidad)
{
    donaciones_necesidad* aux;

    switch (necesidad)
    {
    case 1:
        if(list->alimento == NULL)
        {
            list->alimento = new_donacion;
        }
        else
        {
            for(aux = list->alimento; aux->siguiente_donacion ; aux = aux->siguiente_donacion){}
            aux->siguiente_donacion = new_donacion;
        }
        break;

    case 2:
        if(list->medicina == NULL)
        {
            list->medicina = new_donacion;
        }
        else
        {
            for(aux = list->medicina; aux->siguiente_donacion ; aux = aux->siguiente_donacion){}
            aux->siguiente_donacion = new_donacion;
        }
        break;

    case 3:
        if(list->mantenimiento == NULL)
        {
            list->mantenimiento = new_donacion;
        }
        else
        {
            for(aux = list->mantenimiento; aux->siguiente_donacion ; aux = aux->siguiente_donacion){}
            aux->siguiente_donacion = new_donacion;
        }
        break;
    
    default:
        if(list->reparaciones == NULL)
        {
            list->reparaciones = new_donacion;
        }
        else
        {
            for(aux = list->reparaciones; aux->siguiente_donacion ; aux = aux->siguiente_donacion){}
            aux->siguiente_donacion = new_donacion;
        }
        break;
    }
}

// FUNCIONES ARTICULOS

//funcion que crea una lista articulos
lista_articulos* crear_lista_articulos()
{
    lista_articulos* new_lista_articulos = (lista_articulos*)malloc(sizeof(lista_articulos));
    if(new_lista_articulos ==  NULL)
    {
        printf("error en memoria!!");
        exit(1);
    }

    new_lista_articulos->inicio = NULL;
    return new_lista_articulos;
}

//funcion que crea una estructura articulo
articulo* crear_articulo(char* nombre_articulo, int cantidad, int fecha[])
{
    articulo* new_articulo = (articulo*)malloc(sizeof(articulo));
    if(new_articulo == NULL)
    {
        printf("error de memoria");
        exit(1);
    }
    new_articulo->siguiente_articulo = NULL;

    //reservar memoria y asignar articulo
    new_articulo->articulo = (char*)malloc(sizeof(char) * strlen(nombre_articulo));
    if(new_articulo->articulo == NULL)
    {
        printf("Error de memoria!");
        exit(1);
    }
    strcpy(new_articulo->articulo, nombre_articulo);

    //asignar cantidad
    new_articulo->cantidad = cantidad;
    
    //asignar fecha de nodo_donacion del articulo
    for(int i = 0; i < 3; i++)
    {
        new_articulo->fecha[i] = fecha[i];
    }

    return new_articulo;
}

//funcion ingresa un articulo en la lista articulos
void ingresa_articulo(lista_articulos* list, articulo* new_articulo)
{
    if(list->inicio == NULL)
    {
        list->inicio = new_articulo;
        return;
    }

    //llegar el final de la lista de articulos para ingresarla
    articulo* aux;
    for(aux = list->inicio; aux->siguiente_articulo ; aux = aux->siguiente_articulo){}
    aux->siguiente_articulo = new_articulo;
    return;
}


// FUNCIONES PARA CONTAR

int contar_donaciones(lista_donantes* list, int cedula)
{
    donante* donador = buscar_usuario(list, cedula);
    nodo_donacion* aux;
    int contador;
    for(aux = donador->donaciones; aux ; aux = aux->siguiente_donacion)
    {
        contador++;
    }
    return contador;
}

// FUNCIONES DE LIBERACION DE MEMORIA


// liberar los articulos
void liberar_lista_articulos(lista_articulos* lista_articulos)
{
    articulo* aux;
    
    for(aux = lista_articulos->inicio; lista_articulos->inicio ; aux = lista_articulos->inicio)
    {
        lista_articulos->inicio = aux->siguiente_articulo;
        free(aux);
    }
    return;
}

// liberar las necesidades
void liberar_lista_necesidad(lista_necesidad* lista_necesidad)
{
    donaciones_necesidad* aux;
    
    for(aux = lista_necesidad->alimento; lista_necesidad->alimento ; aux = lista_necesidad->alimento)
    {
        lista_necesidad->alimento = aux->siguiente_donacion;
        free(aux);
    }

    donaciones_necesidad* aux2;

    for(aux2 = lista_necesidad->mantenimiento; lista_necesidad->mantenimiento ; aux2 = lista_necesidad->mantenimiento)
    {
        lista_necesidad->mantenimiento = aux2->siguiente_donacion;
        free(aux);
    }

    for(aux = lista_necesidad->medicina; lista_necesidad->medicina ; aux = lista_necesidad->medicina)
    {
        lista_necesidad->medicina = aux->siguiente_donacion;
        free(aux);
    }

    for(aux = lista_necesidad->reparaciones; lista_necesidad->reparaciones ; aux = lista_necesidad->reparaciones)
    {
        lista_necesidad->reparaciones = aux->siguiente_donacion;
        free(aux);
    }

    return;
}

//funcion libera donantes
void liberar_lista_donantes(lista_donantes* lista_donantes)
{
    donante* aux_donante;
    nodo_donacion* aux_donacion;

    for(aux_donante = lista_donantes->inicio; lista_donantes->inicio ; aux_donante = lista_donantes->inicio)
    {
        lista_donantes->inicio = aux_donante->siguiente_donante;

        //libera las donaciones asignadas al donante
        for(aux_donacion = aux_donante->donaciones; aux_donante->donaciones ; aux_donacion = aux_donante->donaciones)
        {
            aux_donante->donaciones = aux_donacion->siguiente_donacion;
            free(aux_donacion);
        }

        free(aux_donante);
    }

    lista_donantes->final = NULL;
    return;
}


//funcion liberar las listas
void liberar_memoria(lista_articulos* lista_articulos, lista_donantes* lista_donantes, lista_necesidad* lista_necesidad)
{
    liberar_lista_necesidad(lista_necesidad);
    liberar_lista_articulos(lista_articulos);
    liberar_lista_donantes(lista_donantes);
    free(lista_articulos);
    free(lista_donantes);
    free(lista_necesidad);
    return;
}