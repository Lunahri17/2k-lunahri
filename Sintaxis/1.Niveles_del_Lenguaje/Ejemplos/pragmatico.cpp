/* 
 * En este video vamos a observar la dimensión pragmática
 * de los lenguajes formales tomando como referencia 
 * la gramática del lenguaje de programación C.
 * 
 * En la dimensión pragmática de C encontramos los problemas
 * asociados a la ejecución del programa.
 * 
 * - Division por 0.
 * - Lazo infinito. 
 * - Rebasamiento de memoria. 
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int main() {

    int x = 100;
    int y = 0;
    float z = x / y;

    int flag = 1;
    short cantidad = 0;
    while(flag) {
        cantidad++;
    }

    char nombre[50];
    printf("Ingresar nombre: ");
    scanf("%s", nombre);
    printf("Nombre = %s", nombre);
    getchar();

    return 0;
}
