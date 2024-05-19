#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char nombre[80];

    printf("por favor ingrese su nombre: ");
    fgets(nombre, 80, stdin);
    printf("%s", nombre);
    return 0;
}
