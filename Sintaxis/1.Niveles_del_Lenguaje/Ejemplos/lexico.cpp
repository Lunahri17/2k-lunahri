/* 
 * File:   main.cpp
 * Author: usuario
 * Created on 4 de abril de 2020, 14:04
 */

/* 
 * En este video vamos a observar la dimension lexica
 * de los lenguajes formales tomando como referencia 
 * la gramatica del lenguaje de programacion C.
 * 
 * En la dimension lexica de C encontramos por un lado las 
 * palabras reservadas, operadores, separadores y delimitadores:
 * 
 * - tipos de datos: char, short, int, long,float, double
 * - estructuras de control: if, else, for, while, do, break, ...
 * - operadores aritmaticos: +, -, *, /, %, ...
 * - operadores logicos: ||, &&, !
 * - separadores y delimitadores: ", ', (, ), [, ], {, }, ;
 * 
 * Por otro lado tenemos los literales numericos y alfanumericos:
 * 10, 123.45, 'a', "nombre"
 * 
 * Y tambien nombres de variables, nombres de funciones:
 * Los nombres de variables o funciones no pueden comenzar con numeros,
 * tienen que comenzar con una letra o con _, seguida de letras, numeros o _.
 * 
 */

#include <cstdlib>

using namespace std;

int lexico(int argc, char** argv) {

    short cantidad;
    
    int longitud;
    
    long superficie;
    
    cantidad = 40;      // literal numerico notacion decimal.
    
    longitud = 040;     // literal numerico notacion octal.
    
    superficie = 0x40;  // literal numerico notacion hexadecimal.
    
    char simbolo = 'a'; 
    
    char palabra[] = "Sintaxis y Semantica de los Lenguajes";
    
    return 0;
}
