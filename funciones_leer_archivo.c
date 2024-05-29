
# include "funciones_manejo_estructuras.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void leer_donaciones(char nombre_archivo[], lista_donantes* list_donantes, lista_articulos* list_articulos, lista_necesidad* list_necesidad)
{
    FILE* archivo;
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    // aux manejo de cadenas
    char linea[100];
    char subcadena_nombre[100];
    char subcadena_direccion[200];
    char subcadena_aux[50];
    char delimitador[5] = " " ;
    int fecha_aux;
    char delimitador_fecha[5] = "/";
    
    // aux asignar donacion
    int telefono;
    int cedula;

    // aux asignar donacion
    int fecha[3];
    int tipo_donacion;
    char descripcion[100] = "No aplica";
    float valor_monetario = 0;
    int estado_donacion = 1;
    int asignacion  = 0;
    int cantidad = 0;

    if (fgets(linea, sizeof(linea), archivo) == NULL)
    {
        fclose(archivo);
        return;
    }

    
    while(strstr(linea , "--------------------") == NULL )
    {
        if(linea[strlen(linea)-1] == '\n')
        {
            linea[strlen(linea)-1] = '\0';
        }

        if(strstr(linea, "DETALLE DONACIONES") != NULL)
        {
            while(strstr(linea , "--------------------") == NULL)
            {              
                
                if(strstr(linea, "DONANTE:") != NULL)
                {
                    fgets(linea, sizeof(linea), archivo);
                    if(linea[strlen(linea)-1] == '\n')
                    {
                        linea[strlen(linea)-1] = '\0';
                    }

                    for(int i = 1; i < 5; i++)
                    {
                        switch (i)
                        {
                            case 1:
                                goto Cleanup; Cleanup:;
                                char *aux2;
                                strtok(linea, delimitador);
                                int flat = 1;
                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                while(flat)
                                {
                                    char aux[50];
                                    aux2 = strtok(NULL, delimitador);
                                    if(aux2 == NULL)
                                    {
                                        flat = 0;
                                    }
                                    else
                                    {
                                        strcpy(aux, " ");
                                        strcat(aux, aux2);
                                        strcat(subcadena_aux, aux);
                                        
                                        
                                    } 
                                }
                                strcpy(subcadena_nombre, subcadena_aux);
                                if(subcadena_nombre[strlen(subcadena_nombre)-1] == '\n')
                                {
                                    subcadena_nombre[strlen(subcadena_nombre)-1] = '\0';
                                }

                                break;

                            case 2:

                                fgets(linea, sizeof(linea), archivo);
                                if(linea[strlen(linea)-1] == '\n')
                                {
                                  linea[strlen(linea)-1] = '\0';
                                
                                }
                                strtok(linea, delimitador);
                                flat = 1;
                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                while(flat)
                                {
                                    char aux[50];
                                    aux2 = strtok(NULL, delimitador);
                                    if(aux2 == NULL)
                                    {
                                        flat = 0;
                                    }
                                     
                                }

                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                {
                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                }
                                
                                cedula = atoi(subcadena_aux);
                                break;

                            case 3: 

                                fgets(linea, sizeof(linea), archivo);
                                if(linea[strlen(linea)-1] == '\n')
                                {
                                  linea[strlen(linea)-1] = '\0';
                                
                                }
                                strtok(linea, delimitador);
                                flat = 1;
                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                while(flat)
                                {
                                    char aux[50];
                                    aux2 = strtok(NULL, delimitador);
                                    if(aux2 == NULL)
                                    {
                                        flat = 0;
                                    }
                                     
                                }

                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                {
                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                }
                                
                                telefono = atoi(subcadena_aux);
                                break;

                            default:

                                fgets(linea, sizeof(linea), archivo);
                                if(linea[strlen(linea)-1] == '\n')
                                {
                                  linea[strlen(linea)-1] = '\0';
                                
                                }
                                
                                strtok(linea, delimitador);
                                flat = 1;
                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                while(flat)
                                {
                                    char aux[50];
                                    aux2 = strtok(NULL, delimitador);
                                    if(aux2 == NULL)
                                    {
                                        flat = 0;
                                    }
                                    else
                                    {
                                        strcpy(aux, " ");
                                        strcat(aux, aux2);
                                        strcat(subcadena_aux, aux);
                                        
                                    } 
                                }
                                strcpy(subcadena_direccion, subcadena_aux);
                                if(subcadena_direccion[strlen(subcadena_direccion)-1] == '\n')
                                {
                                    subcadena_direccion[strlen(subcadena_direccion)-1] = '\0';
                                }

                                break;
                                
                       
                        }
                    }

                    donante* new_donante = crear_donante(subcadena_nombre, cedula, telefono, subcadena_direccion);
                    insertar_donante(list_donantes, new_donante);
                    
                    fgets(linea, sizeof(linea), archivo);

                    while(strstr(linea , "--------------------") == NULL)
                    {   
                        if(strstr(linea, "DONANTE:") != NULL)
                        {
                            break;
                        }

                        fgets(linea, sizeof(linea), archivo);
                        if(linea[strlen(linea)-1] == '\n')
                        {
                            linea[strlen(linea)-1] = '\0';
                        }

                        if(strstr(linea, "DONACIONES:") != NULL)
                        {
                            while(strstr(linea , "--------------------") == NULL)
                            {
                                if(strstr(linea, "DONANTE:") != NULL)
                                {
                                    break;
                                }

                                fgets(linea, sizeof(linea), archivo);

                                if(linea[strlen(linea)-1] == '\n')
                                {
                                    linea[strlen(linea)-1] = '\0';
                                }

                                if(strstr(linea, "donacion:") != NULL)
                                {
                                    fgets(linea, sizeof(linea), archivo);

                                    if(linea[strlen(linea)-1] == '\n')
                                    {
                                        linea[strlen(linea)-1] = '\0';
                                    }

                                    for(int i = 1; i < 8; i++)
                                    {
                                        switch (i)
                                        {
                                            case 1:
                                                goto Cleanup1; Cleanup1:;                            
                                                char *aux3;
                                                strtok(linea, delimitador);
                                                int flat = 1;
                                                int indice_fecha = 0;
                                                // strcpy(subcadena_aux, strtok(NULL, delimitador_fecha));
                                                while(flat)
                                                {
                                                    aux3 = strtok(NULL, delimitador_fecha);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {
                                                        fecha[indice_fecha] = atoi(aux3);
                                                        indice_fecha++;
                                                    } 
                                                }

                                                break;

                                            case 2:

                                                flat = 1;
                                                fgets(linea, sizeof(linea), archivo);
                                                if(linea[strlen(linea)-1] == '\n')
                                                {
                                                linea[strlen(linea)-1] = '\0';
                                                
                                                }
                                                strcpy(subcadena_aux, strtok(linea, delimitador));
                                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                                while(flat)
                                                {
                                                    char aux[50];
                                                    aux3 = strtok(NULL, delimitador);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {
                                                        strcpy(subcadena_aux, aux3);
                                        
                                                    } 
                                                }

                                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                                {
                                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                                }

                                                if(strcmp(subcadena_aux, "monetario") == 0)
                                                {
                                                    tipo_donacion = 1;
                                                }
                                                else if (strcmp(subcadena_aux, "material") == 0)
                                                {
                                                    tipo_donacion = 2;
                                                }
                                                else
                                                {
                                                    tipo_donacion = 3;
                                                }

                                                break;
                                                

                                            case 3:

                                                fgets(linea, sizeof(linea), archivo);
                                                if(linea[strlen(linea)-1] == '\n')
                                                {
                                                linea[strlen(linea)-1] = '\0';
                                                
                                                }
                                                
                                                strtok(linea, delimitador);
                                                flat = 1;
                                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                                while(flat)
                                                {
                                                    char aux[50];
                                                    aux3 = strtok(NULL, delimitador);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {
                                                        strcpy(aux, " ");
                                                        strcat(aux, aux3);
                                                        strcat(subcadena_aux, aux);
                                                        
                                                    } 
                                                }
                                                
                                                strcpy(descripcion, subcadena_aux);
                                                if(descripcion[strlen(descripcion)-1] == '\n')
                                                {
                                                    descripcion[strlen(descripcion)-1] = '\0';
                                                }

                                                break;
                                               
                                            case 4:
                                                
                                                fgets(linea, sizeof(linea), archivo);
                                                if(linea[strlen(linea)-1] == '\n')
                                                {
                                                linea[strlen(linea)-1] = '\0';
                                                
                                                }

                                                strtok(linea, delimitador);
                                                flat = 1;
                                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                                while(flat)
                                                {
                                                    char aux[50];
                                                    aux3 = strtok(NULL, delimitador);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {                                                                                                            
                                                        strcpy(subcadena_aux, aux3);                                                                                                           
                                                    }
                                                    
                                                }

                                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                                {
                                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                                }
                                                
                                                valor_monetario = (float)strtof(subcadena_aux, NULL);
                                                
                                                break;
                                            
                                            case 5:

                                                fgets(linea, sizeof(linea), archivo);
                                                if(linea[strlen(linea)-1] == '\n')
                                                {
                                                linea[strlen(linea)-1] = '\0';
                                                
                                                }
                                                
                                                strtok(linea, delimitador);
                                                strtok(NULL, delimitador);
                                                flat = 1;
                                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                                while(flat)
                                                {
                                                    char aux[50];
                                                    aux3 = strtok(NULL, delimitador);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {
                                                        strcpy(aux, " ");
                                                        strcat(aux, aux3);
                                                        strcat(subcadena_aux, aux);
                                                        
                                                    } 
                                                }
                                                
                                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                                {
                                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                                }

                                                if(strcmp(subcadena_aux, "disponible") == 0)
                                                {
                                                    estado_donacion = 1;
                                                }
                                                else
                                                {
                                                    estado_donacion = 0;
                                                }

                                                break;
                                            
                                            case 6:

                                                fgets(linea, sizeof(linea), archivo);
                                                if(linea[strlen(linea)-1] == '\n')
                                                {
                                                linea[strlen(linea)-1] = '\0';
                                                
                                                }
                                                
                                                strtok(linea, delimitador);
                                                flat = 1;
                                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                                while(flat)
                                                {
                                                    char aux[50];
                                                    aux3 = strtok(NULL, delimitador);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {
                                                        strcpy(subcadena_aux, aux3);
                                                    } 
                                                }
                                                
                                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                                {
                                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                                }

                                                if(strcmp(subcadena_aux, "alimento") == 0)
                                                {
                                                    asignacion = 1;
                                                }
                                                else if (strcmp(subcadena_aux, "medicina") == 0)
                                                {
                                                    asignacion = 2;
                                                }
                                                else if (strcmp(subcadena_aux, "mantenimiento") == 0)
                                                {
                                                    asignacion = 3;
                                                }
                                                else
                                                {
                                                    asignacion = 4;
                                                }

                                                break;
                                            
                                            case 7:

                                                fgets(linea, sizeof(linea), archivo);
                                                if(linea[strlen(linea)-1] == '\n')
                                                {
                                                linea[strlen(linea)-1] = '\0';
                                                
                                                }

                                                strtok(linea, delimitador);
                                                flat = 1;
                                                strcpy(subcadena_aux, strtok(NULL, delimitador));
                                                while(flat)
                                                {
                                                    char aux[50];
                                                    aux3 = strtok(NULL, delimitador);
                                                    if(aux3 == NULL)
                                                    {
                                                        flat = 0;
                                                    }
                                                    else
                                                    {                                                                                                            
                                                        strcpy(subcadena_aux, aux3);                                                                                                           
                                                    }
                                                    
                                                }

                                                if(subcadena_aux[strlen(subcadena_aux)-1] == '\n')
                                                {
                                                    subcadena_aux[strlen(subcadena_aux)-1] = '\0';
                                                }

                                                if(strcmp(subcadena_aux, "no aplica") != 0)
                                                {
                                                    cantidad = atoi(subcadena_aux);
                                                }
                                                break;
                                            
                                        }

                                    }

                                    nodo_donacion* new_donacion = crear_donacion(fecha, tipo_donacion, descripcion, valor_monetario, cantidad, estado_donacion, asignacion);
                                    insertar_donacion(list_donantes, new_donacion, new_donante->cedula);

                                    donaciones_necesidad* new_donacion_necesidad = crear_donacion_necesidad(new_donacion);
                                    insertar_donacion_necesidad(list_necesidad, new_donacion_necesidad, asignacion);
                                    
                                    if(new_donacion->tipo_donacion == 2)
                                    {
                                        articulo* new_articulo = crear_articulo(descripcion, cantidad, fecha);
                                        ingresa_articulo(list_articulos, new_articulo);
                                    }
                                }
            
                            }
                        }
                    }
                }

                if (fgets(linea, sizeof(linea), archivo) == NULL)
                {
                    fclose(archivo);
                    return;
                }
                
                if(linea[strlen(linea)-1] == '\n')
                {
                    linea[strlen(linea)-1] = '\0';
                }
            }
        }
    
    }

    fclose(archivo);
    return;
}
    