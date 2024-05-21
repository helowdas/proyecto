# include "funciones_escribir_archivo.c"

// borra la informacion del archivo
void reiniciar_archivo(char nombre_archivo[]);

// escribe los detalles donantes en el archivo
void escribir_detalle_donaciones(char nombre_archivo[], lista_donantes* list);

// escribir los detalles donates en el archivo
void escribir_asignacion_nodo_donaciones(char nombre_archivo[], lista_necesidad* lista_necesidad);

// escribe el detalle de articulos
void escribir_detalle_articulos(char nombre_archivo[], lista_articulos* lista_articulos);

// escribe todos los detalles de los donantes
void escribir_detalles_donantes(char nombre_archivo[], lista_donantes* lista_donantes);

// escribe toda la informacion en el archivo
void escribir_archivo(char nombre_archivo[], lista_articulos* list_articulos, lista_donantes* list_donantes, lista_necesidad* list_necesidad);