/* 
 * File:   main.cpp
 * Author: usuario
 * Created on 1 de abril de 2020, 14:04
 */

/* 
 * En este video vamos a observar la dimension sintactica
 * de los lenguajes formales tomando como referencia 
 * la gramatica del lenguaje de programacion C.
 * 
 * En la dimension sintactica de C encontramos las 
 * distintas estructuras del lenguaje como ser:
 * 
 * - sentencias de declaracion y asignacion de variables.
 * - sentenias de definicion de funciones.
 * - bloques de codigo,  {{{... }}}.
 * - expresiones aritmetica y logicas.
 * - estructuras de simbolos apareados, ((( ... ))).
 * - estructuras de control de ejecucion: seleccion. iteracion.
 * 
 */

#include <cstdlib>

using namespace std;

int sintactico(int argc, char** argv) {
    
    char rotulo[] = "Superficie = ";    // Declaracion y asignacion de variable.

    long superficie = 0;
    
    float valor = (superficie * 2) / 10; // Asignacion con expresion aritmetica.   
    
    if (valor > 0) {                     // Seleccion con expresion logica.
        // true -> sentencias
    } else {
        // false -> sentencias
    }
    
    while (valor > 0) {                 // Iteracion con expresion logica.
        // sentencias
    }
    
    return 0;
}

