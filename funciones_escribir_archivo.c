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

void escribir_detalle_donaciones(char nombre_archivo[], lista_donantes* list)
{
    FILE* archivo;
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("DETALLE DONACIONES\n", archivo);
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
        fputs("\n", archivo);
        fputs("DONACIONES:\n", archivo);
        for(aux_nodo_donacion = aux_donante->donaciones; aux_nodo_donacion ; aux_nodo_donacion = aux_nodo_donacion->siguiente_donacion)
        {
            fputs("donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 3; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fputs("\n", archivo);
            fputs("tipo de donacion: ", archivo);
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
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado donacion: disponible\n": "estado donacion: no disponible\n");
            fputs("asignacion: ", archivo);
            switch (aux_nodo_donacion->asignacion)
            {
            case 1:
                fputs("alimento\n", archivo);
                break;
            case 2: 
                fputs("medicina\n", archivo);
                break;
            case 3:
                fputs("mantenimiento\n", archivo);
                break;
            case 4:
                fputs("reparaciones\n", archivo);
                break;
            default:
                fputs("no aplica\n", archivo);
                break;
            }
            
            if (aux_nodo_donacion->cantidad == 0)
            {
                fprintf(archivo, "cantidad: no aplica");
            }
            else
            {
                fprintf(archivo, "cantidad: %d\n", aux_nodo_donacion->cantidad);
            }
            fputs("\n", archivo);
        }
    }

    fputs("--------------------", archivo);
    fclose(archivo);
    return;
}

void escribir_asignacion_donaciones(char nombre_archivo[], lista_necesidad* lista_necesidad)
{
    
    FILE* archivo;
    archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    fputs("\nASIGNACION DONACIONES\n", archivo);
    fputs("\n", archivo);

    donaciones_necesidad* aux_necesidad;
    nodo_donacion* aux_nodo_donacion;
    aux_necesidad = lista_necesidad->alimento;
    fputs("ALIMENTO:\n", archivo);
    fputs("\n", archivo);
    if(aux_necesidad == NULL)
    {
        fputs("LISTA VACIA\n", archivo);
        fputs("\n", archivo);
    }
    else
    {
    for(; aux_necesidad != NULL ;)
        {
            aux_nodo_donacion = aux_necesidad->nodo_donacion;
            aux_necesidad = aux_necesidad->siguiente_donacion;

            fputs("donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 3; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fputs("\n", archivo);
            fputs("tipo de donacion: ", archivo);
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
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado donacion: disponible\n": "estado donacion: no disponible\n");
            fputs("\n", archivo);
        }
    }

    aux_necesidad = lista_necesidad->medicina;
    fputs("MEDICINA:\n", archivo);
    fputs("\n", archivo);
    if(aux_necesidad == NULL)
    {
        fputs("LISTA VACIA\n", archivo);
        fputs("\n", archivo);
    }
    else
    {
    
    for(; aux_necesidad != NULL ;)
        {
            aux_nodo_donacion = aux_necesidad->nodo_donacion;
            aux_necesidad = aux_necesidad->siguiente_donacion;

            fputs("donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 3; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fputs("\n", archivo);
            fputs("tipo de donacion: ", archivo);
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
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado donacion: disponible\n": "estado donacion: no disponible\n");
            fputs("\n", archivo);
        }
    }

    aux_necesidad = lista_necesidad->mantenimiento;
    fputs("MANTENIMIENTO:\n", archivo);
    fputs("\n", archivo);
    if(aux_necesidad == NULL)
    {
        fputs("LISTA VACIA\n", archivo);
        fputs("\n", archivo);
    }
    else
    {
    for(; aux_necesidad != NULL ;)
        {
            aux_nodo_donacion = aux_necesidad->nodo_donacion;
            aux_necesidad = aux_necesidad->siguiente_donacion;

            fputs("donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 3; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fputs("\n", archivo);
            fputs("tipo de donacion: ", archivo);
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
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado donacion: disponible\n": "estado donacion: no disponible\n");
            fputs("\n", archivo);
        }
    }

    aux_necesidad = lista_necesidad->reparaciones;
    fputs("REPARACIONES:\n", archivo);
    fputs("\n", archivo);
    if(aux_necesidad == NULL)
    {
        fputs("LISTA VACIA\n", archivo);
        fputs("\n", archivo);
    }
    else
    {
    for(; aux_necesidad != NULL ;)
        {
            aux_nodo_donacion = aux_necesidad->nodo_donacion;
            aux_necesidad = aux_necesidad->siguiente_donacion;

            fputs("donacion:\n", archivo);
            fputs("fecha: ", archivo);
            for(int i = 0; i < 3; i++)
            {
                fprintf(archivo, "%d/", aux_nodo_donacion->fecha[i]);
            }
            fputs("\n", archivo);
            fputs("tipo de donacion: ", archivo);
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
            fprintf(archivo, aux_nodo_donacion->estado_donacion?"estado donacion: disponible\n": "estado donacion: no disponible\n");
            fputs("\n", archivo);
        }
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
            fprintf(archivo, "cantidad: %d\n", aux_articulos->cantidad);
            fputs("fecha de recepcion: ", archivo);
            for(int i = 0; i < 3; i++)
            {
                fprintf(archivo, "%d/", aux_articulos->fecha[i]);
            }
            fputs("\n", archivo);

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
        fprintf(archivo, "cantidad de donaciones: %d\n", contar_donaciones(lista_donantes, aux_donantes->cedula));
        fputs("\n", archivo);
    }

    fputs("--------------------", archivo);
    fclose(archivo);
    return;
}

void escribir_archivo(char nombre_archivo[], lista_articulos* list_articulos, lista_donantes* list_donantes, lista_necesidad* list_necesidad)
{
    reiniciar_archivo(nombre_archivo);
    escribir_detalle_donaciones(nombre_archivo, list_donantes);
    escribir_asignacion_donaciones(nombre_archivo, list_necesidad);
    escribir_detalle_articulos(nombre_archivo, list_articulos);
    escribir_detalles_donantes(nombre_archivo, list_donantes);
    return;
}
