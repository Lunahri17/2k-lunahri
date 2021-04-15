/* 
 * En este video vamos a observar la dimensi�n pragm�tica
 * de los lenguajes formales tomando como referencia 
 * la gram�tica del lenguaje de programaci�n C.
 * 
 * En la dimensi�n pragm�tica de C encontramos los problemas
 * asociados a la ejecuci�n del programa.
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
