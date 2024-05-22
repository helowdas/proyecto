# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_manejo_estructuras.h"

void leer_donaciones(char nombre_archivo[], lista_donantes* lista_donantes)
{
        FILE* archivo;
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        printf("error a abrir archivo\n");
        return;
    }

    char linea[100];
    char subcadena[50];
    char subcadena_aux[50];
    char delimitador[5] = " " ;
    int fecha_aux;
    char delimitador_fecha[5] = "/";
    

    int asignacion  = 0;
    float valor_monetario = 0;
    int cantidad = 0;
    int fecha[3];
    char descripcion[100] = "No tiene";
    int estado = 1;

    
    while(strcmp(fgets(linea, sizeof(linea), archivo) , "--------------------") != 0)
    {
        if(linea[strlen(linea)-1] == '\n')
        {
            linea[strlen(linea)-1] = '\0';
        }

        if(strstr(linea, "DETALLE DONACIONES") != NULL)
        {
            while(strstr(linea , "--------------------") == NULL)
            {
                
                fgets(linea, sizeof(linea), archivo);
                
                if(linea[strlen(linea)-1] == '\n')
                {
                linea[strlen(linea)-1] == '\0';
                }
                printf("%s\n", linea);

                if(strstr(linea, "DONANTE:") != NULL)
                {
                    fgets(linea, sizeof(linea), archivo);
                    if(linea[strlen(linea)-1] == '\n')
                    {
                        linea[strlen(linea)-1] == '\0';
                    }

                    for(int i = 1; i < 5; i++)
                    {
                        switch (i)
                        {
                            case 1:
                                char *aux2;
                                strtok(linea, delimitador);
                                int flat = 1;
                                strcpy(subcadena, strtok(NULL, delimitador));
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
                                        strcpy(subcadena_aux , aux2);
                                        strcpy(aux, " ");
                                        strcat(aux, subcadena_aux);
                                        strcat(subcadena, aux);
                                    } 
                                }
                                printf("%s", subcadena);
                                return;
                                break;
                        
                        }
                    }
                }
            }
        }
    
    }
}
