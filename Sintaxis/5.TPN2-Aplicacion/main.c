/* 
 * File:   main.c
 * Author: ssl
 * Created on 5 de julio de 2020, 11:22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "automata.h"
// Definir Size
#define SIZE_ISBN 19
#define SIZE_TITULO 41
#define SIZE_AUTOR 31
#define SIZE_EDITORIAL 41
#define SIZE_FECHA 12
#define SIZE_PRECIO 10
#define SIZE_CANTIDAD 6
// Estructura de Registro
typedef struct libro {
    char isbn[SIZE_ISBN];
    char titulo[SIZE_TITULO];
    char autor[SIZE_AUTOR];
    char editorial[SIZE_EDITORIAL];
    char fecha[SIZE_FECHA];
    char precio[SIZE_PRECIO];
    char cantidad[SIZE_CANTIDAD];
    int marca;
} libro;
// Registro Libro
libro registro;
// Estructura Dato de Entrada
typedef struct entrada {
    char rotulo[13];
    char *variable;
    int (*validar)(char *campo);
    int longitud;
} entrada;
// Camposicion de Entrada
entrada campos[] = {
    {"ISBN .....: ", registro.isbn, validar_isbn, SIZE_ISBN},
    {"TITULO ...: ", registro.titulo, validar_titulo, SIZE_TITULO},
    {"AUTOR ....: ", registro.autor, validar_autor, SIZE_AUTOR},
    {"EDITORIAL : ", registro.editorial, validar_editorial, SIZE_EDITORIAL},
    {"FECHA ....: ", registro.fecha, validar_fecha, SIZE_FECHA},
    {"PRECIO ...: ", registro.precio, validar_precio, SIZE_PRECIO},
    {"CANTIDAD .: ", registro.cantidad, validar_cantidad, SIZE_CANTIDAD}
};
// Operaciones
void gestionar(char *archivo);
int imprimir_menu(char *archivo);
int obtener_opcion(int salir);
void procesar(char *archivo, int opcion);
FILE *abrir_archivo(char *archivo, char *modo);
void agregar(FILE *handler);
void modificar(FILE *handler);
void eliminar(FILE *handler);
void compactar(FILE *handler, char *archivo);
void listar(FILE *handler);
void consultar(FILE *handler);
int ingresar_dato(entrada datos);
long buscar_isbn(FILE *handler);
void mostrar(libro registro);
void mensaje (char *mensaje);
// Item de Menu
typedef struct menu_item {
    char rotulo[20];
    char modo[3];
    void (*funcion1)(FILE *handler);
    void (*funcion2)(FILE *handler, char *archivo);
} menu_item;
// Opciones de Menu
menu_item opciones[] = {
    {"Agregar.", "a+b", agregar, NULL},
    {"Modificar.", "r+b", modificar, NULL},
    {"Eliminar.", "r+b", eliminar, NULL},
    {"Compactar", "rb", NULL, compactar},
    {"Listar", "rb", listar, NULL},
    {"Consultar", "rb", consultar, NULL}
};
// Gestionar datos de Libros
void gestionar(char *archivo) {
    int opcion = 0;
    int salir = 0;
    do {
        salir = imprimir_menu(archivo);
        opcion = obtener_opcion(salir);
        if (opcion < salir) {
            procesar(archivo, opcion);
        }
    } while (opcion < salir);
    mensaje("*** Fin Gestionar ***\n\n");
}
// Mostrar Menu por consola
int imprimir_menu(char *archivo) {
    system("cls");
    printf("\nArchivo a gestionar %s.\n", archivo);
    printf("----------------------\n");
    printf("Opciones disponibles: \n");
    int salir = sizeof(opciones) / sizeof(menu_item);  
    for (int i = 0; i < salir; i++) {
        printf(" %d - %s \n", i + 1, opciones[i].rotulo);
    }
    printf(" %d - SALIR.\n", salir + 1);
    return salir;
}
// Ingresar Opcion
int obtener_opcion(int salir) {
    char opcion;
    do {
        printf("Ingresar Opcion: ");
        opcion = getchar() - '0';
        if (opcion < 1 || opcion > salir + 1) {
            mensaje("\n Error: Opcion Incorrecta.\n");
        }
    } while (opcion < 1 || opcion > salir + 1);
    getchar(); // limpia enter del buffer de entrada
    return opcion - 1;
};
// Procesar Archivo
void procesar(char *archivo, int opcion) {
    system("cls");
    printf(" %s\n", opciones[opcion].rotulo);
    FILE *handler = abrir_archivo(archivo, opciones[opcion].modo);
    if (handler != NULL) {
        // Operacion particular
        (opciones[opcion].funcion1 != NULL) ?
        (*opciones[opcion].funcion1)(handler) :
        (*opciones[opcion].funcion2)(handler, archivo);
        fclose(handler);
    }
    char texto[51];
    snprintf(texto, 50, "*** Fin %s *** \n", opciones[opcion].rotulo);
    mensaje(texto);
}
// Apertura de Archivo
FILE *abrir_archivo(char *archivo, char *modo) {
    FILE *handler = fopen(archivo, modo);
    if (handler == NULL) {
        printf("Error: Apertura archivo %s.\n", archivo);
        getchar();
    }
    return handler;
}
// Agregar Registro al Archivo
void agregar(FILE *handler) {
    if (ingresar_dato(campos[0]) == 1) {
       	long posicion = buscar_isbn(handler);
       	if (posicion == -1L) {
           for (int i = 1; i < 7; i++) {
          	if (ingresar_dato(campos[i]) == -1) {
                    i--;
                }
            }
            registro.marca = 1;
            fwrite(&registro, sizeof(libro), 1, handler);
            mostrar(registro);
        } else {
            mensaje("\n*** ISBN existente ***\n");
        }
    } else {
    	mensaje("Agregar cancelado. \n");
    }
}
// Modificar Registro de Archivo
void modificar(FILE *handler) {
    int opcion = 0;
    if (ingresar_dato(campos[0]) == 1) {
      	long posicion = buscar_isbn(handler);
       	if (posicion != -1L) {
            mostrar(registro);
            do {
               	printf("\n Seleccione campo a modificar:");
               	printf("\n 1.- Titulo.");
               	printf("\n 2.- Autor.");
               	printf("\n 3.- Editorial.");
               	printf("\n 4.- Fecha.");
               	printf("\n 5.- Precio.");
               	printf("\n 6.- Cantidad.");
               	printf("\n 7.- Salir.");
               	printf("\n Ingrese opcion: ");
               	scanf("%d", &opcion);
               	getchar();
               	if (opcion > 0 && opcion < 7) {
                    ingresar_dato(campos[opcion]);
                }
            } while (opcion != 7);
            fseek(handler, posicion, SEEK_SET);
            fwrite(&registro, sizeof(libro), 1, handler);
            mostrar(registro);
        } else {
            mensaje("*** El registro no existe ***\n");
        }
    } else {
        mensaje("Modificar cancelado. \n");
    }
 }
// Eliminar Registro de Archivo (Baja Logica)
void eliminar(FILE *handler) {
    int opcion;
    if (ingresar_dato(campos[0]) == 1) {
      	long posicion = buscar_isbn(handler);
       	if (posicion != -1L) {
            mostrar(registro);
            printf("\nDesea borrar registro (s/n)?: ");
            opcion = getchar();
            if (opcion == 's' || opcion == 'S') {
         	registro.marca = 0;
                fseek(handler, posicion, SEEK_SET);
                fwrite(&registro, sizeof(libro), 1, handler);
                mensaje("\nRegistro borrado \n");
           }
        } else {
            mensaje("*** El registro no existe ***\n");
	}
    } else {
        mensaje("*** Eliminar cancelado. *** \n");
    }
}
// Compactar Archivo
void compactar(FILE *handler, char *archivo) {
    FILE *handler1 = abrir_archivo("auxiliar.dat", "wb");
    if (handler != NULL && handler1 != NULL) {
        long size = sizeof (libro);
        do {
            fread(&registro, size, 1, handler);
            if (!feof(handler)) {
                if (registro.marca == 0) {
                    printf("\n Registro eliminado en forma fisica \n");
                    mostrar(registro);
                } else {
                    fwrite(&registro, size, 1, handler1);
                }
            }
        } while(!feof(handler));
        fclose(handler);
        fclose(handler1);
        remove(archivo);
        rename("auxiliar.dat", archivo);
    }
}
// Listar Archivo
void listar(FILE *handler) {
    do {
        fread(&registro, sizeof(libro), 1, handler);
        if (!feof(handler) && (registro.marca == 1)) {
            mostrar(registro);
        }
    } while(!feof(handler));
}
// Consultar Archivo
void consultar(FILE *handler) {
    if (ingresar_dato(campos[0]) == 1) {
       	if (buscar_isbn(handler) != -1L) {
           mostrar(registro);
        } else {
            mensaje("** El registro no existe ***\n");
        }
    } else {
        mensaje("** Consultar cancelado. ***\n");
    }
}
/*
 * Rutina Principal
 */
// Ingrsar datos de Registro
int ingresar_dato(entrada datos) {
    int valido = 0;
    int longitud = 0;
    do {
        printf("\n%s", datos.rotulo);
        fflush(stdin);
        fgets(datos.variable, datos.longitud, stdin);
        longitud = strlen(datos.variable) - 1;
        datos.variable[longitud] = (datos.variable[longitud] == 10) ? '\0' :
            datos.variable[longitud];
        if (strlen(datos.variable) > 1) {
            valido = ((*datos.validar)(datos.variable));
            if (!valido) {
                printf("Error: Dato no valido. \n");
            }
	} else {
            valido = -1;
	}
    } while (!valido);
    return valido;
}
// Buscar registro por ISBN
long buscar_isbn(FILE *handler) {
    char dato[18];
    strncpy(dato, registro.isbn, SIZE_ISBN);
    long posicion = -1L;
    int size = sizeof(libro);
    rewind(handler);
    do {
        fread(&registro, size, 1, handler);
        if (!feof(handler) && registro.marca == 1 && strcmp(registro.isbn, dato) == 0) {
            posicion = ftell(handler) - size;
        }
    } while(!feof(handler) && posicion == -1L);
    strncpy(registro.isbn, dato, SIZE_ISBN);
    return posicion;
}
// Mostrar Registro
void mostrar(libro registro) {
    printf("\nISBN ....: %s", registro.isbn);
    printf("\nTitulo ..: %s", registro.titulo);
    printf("\nAutor ...: %s", registro.autor);
    printf("\nEditorial: %s", registro.editorial);
    printf("\nFecha ...: %s", registro.fecha);
    printf("\nPrecio ..: %s", registro.precio);
    printf("\nCantidad : %s", registro.cantidad);
    printf("\nMarca ...: %d", registro.marca);
    printf("\n --------------------------------------------\n");
}
// Imprimir Mensaje
void mensaje (char *mensaje) {
    printf("%s", mensaje);
    getchar();
}

int main(int argc, char** argv) {
    int exit_code = EXIT_SUCCESS;
    if (argc < 2) {
        printf("Error: Falta nombre del archivo a gestionar.\n");
        exit_code = EXIT_FAILURE;
    } else {
        // Nombre de Archivo
        char archivo[30];
        strncpy(archivo, argv[1], sizeof(archivo));
        gestionar(archivo);
    }
    return exit_code;
}
