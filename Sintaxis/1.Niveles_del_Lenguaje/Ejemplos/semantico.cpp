/* 
 * File:   main.cpp
 * Author: usuario
 * Created on 5 de abril de 2020, 14:04
 */

/* 
 * En este video vamos a observar la dimension semantica
 * de los lenguajes formales tomando como referencia 
 * la gramatica del lenguaje de programacion C.
 * 
 * En la dimension semantica de C encontramos con el significado
 * de las distintas estructuras del lenguaje en funcion del contexto.
 * 
 * - Sentencia de control break.
 * - Sentencia de asignacion de variable a la cual le falta la
 *   declaracion de variable. 
 * - Asignacion de variables con tipos de datos compatibles.
 * 
 */

#include <cstdlib>

using namespace std;

int semantico(int argc, char** argv) {
    
    char rotulo[20.5] = "Superficie = "; // Dimension del arreglo debe ser entera.

    long superficie = "123";    // Asignacion con tipo de dato incompatible
    
    valor = (superficie * 2) / 10; // Asignacion sin declaracion de variable.   
    
    while (valor > 0) {            // Variable no definida.

    }
    
    break;

    return 0;
}

