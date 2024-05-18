//FUNCIONES.H

# include "funciones_jean.c"
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

}lista_donantes;

// NODO ARTICULOS

typedef struct articulos
{
    char *articulo;
    int cantidad;
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3

}articulo;


// FUNCIONES


