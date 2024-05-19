# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "funciones_jean.h"

void main()
{
    printf("%d", 5);
    donacion* don = (donacion*)malloc(sizeof(donacion));
    don->fecha[0] = 3;
    printf("%d", don->fecha[0]);
}

