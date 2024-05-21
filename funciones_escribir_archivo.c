# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"

void reiniciar_archivo(char nombre_archivo[])
{
    FILE* archivo;
    archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }
    fclose(archivo);
    return;
}

void escribir_detalle_nodo_donaciones(char nombre_archivo[], lista_donantes* list)
{
    FILE* archivo;
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("DETALLE nodo_donacionES\n", archivo);
    fputs("\n", archivo);

    donante* aux_donante;
    nodo_donacion* aux_nodo_donacion;

    for(aux_donante = list->inicio; aux_donante ; aux_donante = aux_donante->siguiente_donante)
    {
        fputs("DONANTE:\n", archivo);
        fprintf(archivo, "nombre: %s\n", aux_donante->nombre);
        fprintf(archivo, "cedula: %d\n", aux_donante->cedula);
        fprintf(archivo, "telefono: %d\n", aux_donante->telefono);
        fprintf(archivo, "dirreccion: %s\n", aux_donante->direccion);
        fputs("nodo_donacionES:\n", archivo);
        for(aux_nodo_donacion = aux_donante->donaciones; aux_nodo_donacion ; aux_nodo_donacion = aux_nodo_donacion->siguiente_donacion)
        {
            fputs("nodo_donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 2; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fprintf(archivo, "%d\n", aux_nodo_donacion->fecha[2]);
            fputs("tipo de nodo_donacion: ", archivo);
            switch (aux_nodo_donacion->tipo_donacion)
            {
            case 1:
                fputs("monetario\n", archivo);
                break;
            case 2: 
                fputs("material\n", archivo);
                break;
            default:
                fputs("voluntariado\n", archivo);
                break;
            }
            fprintf(archivo, "descripcion: %s\n", aux_nodo_donacion->descripcion);
            if(aux_nodo_donacion->valor_monetario == (float)0)
            {
                fprintf(archivo, "valor monetario: no aplica\n");
            }
            else
            {
                fprintf(archivo, "valor monetario: %.2f\n", aux_nodo_donacion->valor_monetario);
            }
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado nodo_donacion: disponible\n": "estado nodo_donacion: no disponible\n");
            fputs("\n", archivo);
        }
    }

    fputs("--------------------", archivo);
    fclose(archivo);
    return;
}

void escribir_asignacion_nodo_donaciones(char nombre_archivo[], lista_necesidad* lista_necesidad)
{
    
    FILE* archivo;
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("\nASIGNACION nodo_donacionES\n", archivo);
    fputs("\n", archivo);

    donaciones_necesidad* aux_necesidad;
    aux_necesidad = lista_necesidad->alimento;
    fputs("ALIMENTO:\n", archivo);
    fputs("\n", archivo);
    nodo_donacion* aux_nodo_donacion;

    for(aux_nodo_donacion = aux_necesidad->nodo_donacion; aux_necesidad ; aux_nodo_donacion = aux_necesidad->nodo_donacion)
        {
            aux_necesidad = aux_necesidad->siguiente_donacion;

            fputs("nodo_donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 2; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fprintf(archivo, "%d\n", aux_nodo_donacion->fecha[2]);
            fputs("tipo de nodo_donacion: ", archivo);
            switch (aux_nodo_donacion->tipo_donacion)
            {
            case 1:
                fputs("monetario\n", archivo);
                break;
            case 2: 
                fputs("material\n", archivo);
                break;
            default:
                fputs("voluntariado\n", archivo);
                break;
            }
            fprintf(archivo, "descripcion: %s\n", aux_nodo_donacion->descripcion);
            if(aux_nodo_donacion->valor_monetario == (float)0)
            {
                fprintf(archivo, "valor monetario: no aplica\n");
            }
            else
            {
                fprintf(archivo, "valor monetario: %.2f\n", aux_nodo_donacion->valor_monetario);
            }
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado nodo_donacion: disponible\n": "estado nodo_donacion: no disponible\n");
            fputs("\n", archivo);
        }

    aux_necesidad = lista_necesidad->medicina;
    fputs("MEDICINA:\n", archivo);
    fputs("\n", archivo);

    for(aux_nodo_donacion = aux_necesidad->nodo_donacion; aux_necesidad ; aux_nodo_donacion = aux_necesidad->nodo_donacion)
        {
            aux_necesidad = aux_necesidad->siguiente_donacion;
            
            fputs("nodo_donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 2; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fprintf(archivo, "%d\n", aux_nodo_donacion->fecha[2]);
            fputs("tipo de nodo_donacion: ", archivo);
            switch (aux_nodo_donacion->tipo_donacion)
            {
            case 1:
                fputs("monetario\n", archivo);
                break;
            case 2: 
                fputs("material\n", archivo);
                break;
            default:
                fputs("voluntariado\n", archivo);
                break;
            }
            fprintf(archivo, "descripcion: %s\n", aux_nodo_donacion->descripcion);
            if(aux_nodo_donacion->valor_monetario == (float)0)
            {
                fprintf(archivo, "valor monetario: no aplica\n");
            }
            else
            {
                fprintf(archivo, "valor monetario: %.2f\n", aux_nodo_donacion->valor_monetario);
            }
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado nodo_donacion: disponible\n": "estado nodo_donacion: no disponible\n");
            fputs("\n", archivo);
        }

    aux_necesidad = lista_necesidad->mantenimiento;
    fputs("MANTENIMIENTO:\n", archivo);
    fputs("\n", archivo);

    for(aux_nodo_donacion = aux_necesidad->nodo_donacion; aux_necesidad ; aux_nodo_donacion = aux_necesidad->nodo_donacion)
        {
            aux_necesidad = aux_necesidad->siguiente_donacion;
            
            fputs("nodo_donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 2; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fprintf(archivo, "%d\n", aux_nodo_donacion->fecha[2]);
            fputs("tipo de nodo_donacion: ", archivo);
            switch (aux_nodo_donacion->tipo_donacion)
            {
            case 1:
                fputs("monetario\n", archivo);
                break;
            case 2: 
                fputs("material\n", archivo);
                break;
            default:
                fputs("voluntariado\n", archivo);
                break;
            }
            fprintf(archivo, "descripcion: %s\n", aux_nodo_donacion->descripcion);
            if(aux_nodo_donacion->valor_monetario == (float)0)
            {
                fprintf(archivo, "valor monetario: no aplica\n");
            }
            else
            {
                fprintf(archivo, "valor monetario: %.2f\n", aux_nodo_donacion->valor_monetario);
            }
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado nodo_donacion: disponible\n": "estado nodo_donacion: no disponible\n");
            fputs("\n", archivo);
        }

    aux_necesidad = lista_necesidad->reparaciones;
    fputs("REPARACIONES:\n", archivo);
    fputs("\n", archivo);

    for(aux_nodo_donacion = aux_necesidad->nodo_donacion; aux_necesidad ; aux_nodo_donacion = aux_necesidad->nodo_donacion)
        {
            aux_necesidad = aux_necesidad->siguiente_donacion;
            
            fputs("nodo_donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 2; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fprintf(archivo, "%d\n", aux_nodo_donacion->fecha[2]);
            fputs("tipo de nodo_donacion: ", archivo);
            switch (aux_nodo_donacion->tipo_donacion)
            {
            case 1:
                fputs("monetario\n", archivo);
                break;
            case 2: 
                fputs("material\n", archivo);
                break;
            default:
                fputs("voluntariado\n", archivo);
                break;
            }
            fprintf(archivo, "descripcion: %s\n", aux_nodo_donacion->descripcion);
            if(aux_nodo_donacion->valor_monetario == (float)0)
            {
                fprintf(archivo, "valor monetario: no aplica\n");
            }
            else
            {
                fprintf(archivo, "valor monetario: %.2f\n", aux_nodo_donacion->valor_monetario);
            }
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado nodo_donacion: disponible\n": "estado nodo_donacion: no disponible\n");
            fputs("\n", archivo);
        }
    
    fputs("--------------------", archivo);
    fclose(archivo);
    return;
}

void escribir_detalle_articulos(char nombre_archivo[], lista_articulos* lista_articulos)
{
    FILE* archivo;
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("\nDETALLES ARTICULOS\n", archivo);
    fputs("\n", archivo);

    articulo* aux_articulos;

     for(aux_articulos = lista_articulos->inicio; aux_articulos ; aux_articulos = aux_articulos->siguiente_articulo)
        {
            fputs("articulo:\n", archivo);
            fprintf(archivo, "nombre: %s\n", aux_articulos->articulo);
            fprintf(archivo, "cantidad: %d", aux_articulos->cantidad);
            fputs("fecha de recepcion: ", archivo);
            for(int i = 0; i < 2; i++)
            {
                fprintf(archivo, "%d/", aux_articulos->fecha[i]);
            }
            fprintf(archivo, "%d\n", aux_articulos->fecha[2]);

            fputs("\n", archivo);
        }
    
    fputs("--------------------", archivo);
    fclose(archivo);
    return;
}


void escribir_detalles_donantes(char nombre_archivo[], lista_donantes* lista_donantes)
{
    FILE* archivo;
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("\nDETALLES DONANTES\n", archivo);
    fputs("\n", archivo);   

    donante* aux_donantes;

    for(aux_donantes = lista_donantes->inicio; aux_donantes ; aux_donantes = aux_donantes->siguiente_donante)
    {
        fputs("DONANTE:\n", archivo);
        fprintf(archivo, "nombre: %s\n", aux_donantes->nombre);
        fprintf(archivo, "cedula: %d\n", aux_donantes->cedula);
        fprintf(archivo, "telefono: %d\n", aux_donantes->telefono);
        fprintf(archivo, "dirreccion: %s\n", aux_donantes->direccion);
        fprintf(archivo, "cantidad de nodo_donaciones: %d", contar_nodo_donaciones(lista_donantes, aux_donantes->cedula));
    }

    fputs("--------------------", archivo);
    fclose(archivo);
    return;
}

void escribir_archivo(char nombre_archivo[], lista_articulos* list_articulos, lista_donantes* list_donantes, lista_necesidad* list_necesidad)
{
    reiniciar_archivo(nombre_archivo);
    escribir_detalle_nodo_donaciones(nombre_archivo, list_donantes);
    escribir_asignacion_nodo_donaciones(nombre_archivo, list_necesidad);
    escribir_detalle_articulos(nombre_archivo, list_articulos);
    escribir_detalles_donantes(nombre_archivo, list_donantes);
    return;
}

