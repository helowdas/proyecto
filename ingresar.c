#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
#define longitud_fecha 3


// funcion para ingresar datos de donantes

void ingresarDonante() {

    char *nombre[80];
    int cedula;
    int telefono; 
    char *direccion[200];


    printf("ingrese su nombre: ");
    fgets(nombre, 80 , stdin);

    printf("ingrese su cedula: ");
    scanf("%d", &cedula);

    printf("ingrese su numero de telefono: ");
    scanf("%d", &telefono);

    printf("ingrese su direccion: ");
    fgets(direccion, 200 , stdin);

    getchar();


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

    //funcion para asignar la necesidad
    int asignarNecesidad(){
        
        int opcion;
        
        //asignar la necesidad

        printf("escoge el numero a donde quiere asignar su donacion \n1.alimento, \n2.medicina, \n3.mantemiento, \n4.reparacion: ");
        scanf("%d", &opcion);

        return opcion; 



    }



int main()
{
    donante *cabeza = NULL;

    donaciones *cabeza_donaciones = NULL;

    ingresarDonante();

    ingresarDonacion();

    return 0;
}
