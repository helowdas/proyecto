#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define longitud_fecha 3

// este typedef funciona para la funcion ingrearDonacion
typedef struct donaciones
{
    int fecha[longitud_fecha]; // dias, mes, año; longitud 3
    int tipo_donacion;         // 1 = monetaria, 2 = material, 3 = voluntariado
    char *descripcion;
    float valor_monetario;
    int estado_donacion;
    struct donaciones *siguiente_donacion;
} donaciones;

// este typedef funciona para la funcion ingresarDonante
typedef struct donante
{
    char *nombre;
    int cedula;
    int telefono;
    char *direccion;
    struct donante *siguiente_donante;
    struct donante *anterior_donante;
} donante;

// funcion para ingresar datos de donantes

void ingresarDonante(donante *cabeza) {
    // Creo el nuevo nodo para donante
    donante* nuevoDonante = (donante*)malloc(sizeof(donante));

    nuevoDonante->nombre = (char*)malloc(100 * sizeof(char));
    nuevoDonante->cedula = malloc(sizeof(int));
    nuevoDonante->telefono = malloc(sizeof(int));
    nuevoDonante->direccion = (char*)malloc(100 * sizeof(char));

    printf("Ingrese el nombre del donante: ");
    fgets(nuevoDonante->nombre, 100, stdin);
    nuevoDonante->nombre[strcspn(nuevoDonante->nombre, "\n")] = '\0';

    printf("Ingrese la cedula del donante: ");
    scanf("%d", nuevoDonante->cedula);
    
    printf("Ingrese el telefono del donante: ");
    scanf("%d", nuevoDonante->telefono);
  
    printf("Ingrese la direccion del donante: ");
    fgets(nuevoDonante->direccion, 100, stdin);
    nuevoDonante->direccion[strcspn(nuevoDonante->direccion, "\n")] = '\0';

    getchar(); // Para limpiar el buffer 

    // Enlaza el nuevo nodo a la lista existente
    nuevoDonante->siguiente_donante = cabeza;
    cabeza = nuevoDonante;
}

// funcion para ingresar los donantes

donaciones *ingresarDonacion()
{

    float valor_monetario;
    int tipo_donacion;
    int cantidad;
    // array auxiliar
    int fecha[3];
    char *aux = "no tiene descripcion";
    // si char existe (tipo material) envio el nombre del articulo

    printf("Ingrese la fecha (dia): ");
    scanf("%d", &fecha[0]);

    printf("Ingrese la fecha (mes): ");
    scanf("%d", &fecha[1]);

    printf("Ingrese la fecha (año): ");
    scanf("%d", &fecha[2]);

    printf("Ingrese el tipo de donación (1 = monetaria, 2 = material, 3 = voluntariado): ");
    scanf("%d", &tipo_donacion);

    if (tipo_donacion == 2)
    {
        printf("Ingrese la cantidad del material");
        scanf("%d", &cantidad);
        printf("Ingrese la descripcion del material: ");
        fgets(aux, 100, stdin);
    }

    printf("Ingrese el valor monetario: ");
    scanf("%f", &valor_monetario);
}

int main()
{
    donante *cabeza = NULL;

    donaciones *cabeza_donaciones = NULL;

    ingresarDonante(cabeza);

    ingresarDonacion();

    return 0;
}
