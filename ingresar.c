#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_manejo_estructuras.c"
#define longitud_fecha 3

// Función para ingresar datos de donantes
donante *ingresarDonante(lista_donantes *Lista_donante)
{
    char nombre[80];
    int cedula;
    int telefono;
    char direccion[200];

    printf("ingrese su nombre: ");
    fgets(nombre, 80, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("ingrese su cedula: ");
    scanf("%d", &cedula);
    getchar();


    printf("ingrese su numero de telefono: ");
    scanf("%d", &telefono);
    getchar();

    printf("ingrese su direccion: ");
    fgets(direccion, 200, stdin);
    direccion[strcspn(direccion, "\n")] = 0;

    donante *donador = crear_donante(nombre, cedula, telefono, direccion);

    insertar_donante(Lista_donante, donador);

    printf("Usuario registrado con exito. \n");

    return donador;
}

// funcion para ingresar los donantes
nodo_donacion *ingresarDonacion(lista_donantes *Lista_donante, donante *donador, lista_articulos *listado_articulo)
{

    float valor_monetario;
    int cantidad;
    int fecha[3];
    char aux[100];
    int estado;
    int asignacion;

    printf("Ingrese la fecha. \n");

    printf("día: ");
    scanf("%d", &fecha[0]);
    getchar();

    printf("mes: ");
    scanf("%d", &fecha[1]);
    getchar();

    printf("año: ");
    scanf("%d", &fecha[2]);
    getchar();

    printf("\n");

    int tipo_donacion;
    printf("Ingrese el tipo de donación (1 = monetaria, 2 = material, 3 = voluntariado): ");
    scanf("%d", &tipo_donacion);
    getchar();

    if (tipo_donacion == 1)
    {
        printf("Ingrese el valor monetario: ");
        scanf("%d", &valor_monetario);
        getchar();
    }

    else if (tipo_donacion == 2)
    {
        printf("Ingrese la cantidad del material: ");
        scanf("%d", &cantidad);
        getchar();

        printf("Ingrese la descripción del material: ");
        fgets(aux, 100, stdin);

        // implementar funcion crear articulo

        struct articulos *nuevo_articulo = crear_articulo(aux, cantidad, fecha);

        // implementar guardar articulo

        ingresa_articulo(listado_articulo, nuevo_articulo);
    }

    nodo_donacion *nueva_donacion = crear_donacion(fecha, tipo_donacion, aux, valor_monetario, cantidad, estado, asignacion);

    if (donador->donaciones == NULL)
    {

        donador->donaciones = nueva_donacion;
    }
    else
    {

        nodo_donacion *actual = donador->donaciones;
        while (actual->siguiente_donacion != NULL)
        {
            actual = actual->siguiente_donacion;
        }
        actual->siguiente_donacion = nueva_donacion;
    }

    return nueva_donacion;
}

// funcion para asignar la necesidad
void asignarNecesidad(lista_donantes *Lista_donante, lista_necesidad *listado_necesidad, nodo_donacion *nueva_donacion)
{

    int opcion;

    // asignar la necesidad

    printf("escoge el numero a donde quiere asignar su donacion \n1.alimento, \n2.medicina, \n3.mantemiento, \n4.reparacion: ");
    scanf("%d", &opcion);

    // Aquí puedes usar tanto lista_donantes como listado_necesidad

    donaciones_necesidad *necesidad_donativo = crear_donacion_necesidad(nueva_donacion);

    insertar_donacion_necesidad(listado_necesidad, necesidad_donativo, opcion);
}

int registro()
{
    char registro[10];
    printf("si/no: ");
    scanf("%s", &registro);

    if (strcmp(registro, "si") == 0 || strcmp(registro, "SI") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int donar(lista_donantes *Lista_donante, lista_necesidad *listado_necesidad, lista_articulos *listado_articulo, donante *donador)
{

    printf("para ingresar una donacion tiene que estar registrado. ¿esta registrado? ");

    if (registro())
    {
        int cedula;
        printf("ingrese su cedula para verificar: ");
        scanf("%d", &cedula);

        

        getchar();

        if (usuario_existe(Lista_donante, cedula) == 1)
        {
            printf("Usuario encontrado.\n");

            //donacion *donador = ingresarDonante(Lista_donante)

            

            printf("¿Desea ingresar una donación?");
            if (registro())
            {
                
                nodo_donacion *nueva_donacion = ingresarDonacion(Lista_donante, donador, listado_articulo);
                printf("%p", (void*)nueva_donacion); //printf para verificar si esta guardando bien los datos 
                asignarNecesidad(Lista_donante, listado_necesidad, nueva_donacion);
            }
            else
            {
                return 1;
            }
        }
        else
        {

            printf("Usuario no encontrado.\n");
            return 1;
        }
    }
    else
    {
        printf("desea registrarse? \n: ");

        if (registro())
        {
            donante *donador = ingresarDonante(Lista_donante);
            insertar_donante(Lista_donante, donador);
            nodo_donacion *nueva_donacion = ingresarDonacion(Lista_donante, donador, listado_articulo);
            asignarNecesidad(Lista_donante, listado_necesidad, nueva_donacion);
        }
        else
        {
            return 1;
        }
    }
}

int main()
{

    int bandera = 1;
    int opcion = 1;

    lista_articulos *listado_articulo = crear_lista_articulos();

    lista_donantes *Lista_donante = crear_lista_donantes();

    lista_necesidad *listado_necesidad = crear_lista_necesidad();

    donante *donador = NULL;


    while (bandera != 0)
    {

        printf("Opcion 1 = registrarse\n Opcion 2 = donar\n Opcion 3 = guardar\n Opcion 4 = salir\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            ingresarDonante(Lista_donante);
        }
        else if (opcion == 2)
        {
            donar(Lista_donante, listado_necesidad, listado_articulo, donador);
        }
        else if (opcion == 3)
        {
            //
            printf("\n");
        }
        else if (opcion == 4)
        {
            liberar_memoria(listado_articulo, Lista_donante, listado_necesidad);
            printf("Programa Finalizado.");
            bandera = 0;
        }
        else
        {
            printf("opcion no valido");
        }
    }

    return 0;
}