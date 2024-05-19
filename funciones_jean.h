//FUNCIONES.H

# include "funciones_jean.c"
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

}lista_donantes;

// NODOS PARA NECESIDADES DEL REFUGIO

typedef struct donaciones_necesidad
{
    donacion* donacion;
    struct donaciones_necesidad* siguiente_donacion;
    
}donaciones_necesidad;

typedef struct necesidad
{
    donaciones_necesidad* alimento; // = 1
    donaciones_necesidad* medicina; // = 2
    donaciones_necesidad* mantenimiento; // = 3
    donaciones_necesidad* reparaciones; // = 4

}lista_necesidad;

// NODO ARTICULOS

typedef struct articulos
{
    char *articulo;
    int cantidad;
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3
    struct articulos* siguiente_articulo;

}articulos;

typedef struct
{
    articulos* inicio;

}lista_articulos;


// FUNCIONES PARA DONANTES

//crea estructuras lista de donantes

lista_donantes* crear_lista_donantes;


