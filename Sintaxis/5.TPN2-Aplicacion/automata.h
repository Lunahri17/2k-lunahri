/* 
 * File:   automata.h
 * Author: ssl
 * Created on 5 de julio de 2020, 11:22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estados
#define Q0   0
#define Q1   1
#define Q2   2
#define Q3   3
#define Q4   4
#define Q5   5
#define Q6   6
#define Q7   7
#define Q8   8
#define Q9   9
#define Q10 10
#define Q11 11
#define Q12 12
#define Q13 13
#define Q14 14
#define Q15 15
#define Q16 16
#define Q17 17
#define Q18 18
#define Q19 19
#define Q20 20
#define Q21 21
#define Q22 22
#define Q23 23
#define Q24 24
#define Q25 25
#define Q26 26
// Validaciones
int validar_isbn(char *isbn);
int validar_titulo(char *titulo);
int validar_editorial(char *editorial);
int validar_autor(char *autor);
int validar_fecha(char *fecha);
int validar_precio(char *precio);
int validar_cantidad(char *cantidad);
// Convertir simbolo de entrada a indice
int indice(char alfabeto[], char simbolo) {
    int index = -1;
    int i = 0;
    while(i < strlen(alfabeto) && index < 0) {
        simbolo = isupper(simbolo) ? 'X' :
                 (islower(simbolo) ? 'x' : simbolo);
        if (simbolo == alfabeto[i]) {
            index = i;
        }
        i++;
	}   
    return index;
}
// Controlar si estado es final
int esFinal(int estado, int finales[], int n) {
    int resultado = 0;
    int i = 0;
    while (i < n && resultado == 0) {
        if (estado == finales[i]) {
            resultado = 1;
        }
        i++;
    }
    return resultado;
}
//int automata(char *alfabeto, int *matriz, int n, int *finales, int f, char *secuencia);
// Automata Finito
int automata(char *alfabeto, int *matriz, int n,
        int *finales, int f, char *secuencia) {
    int estado = Q0;
    for (int i = 0; i < strlen(secuencia); i++) {
        if (secuencia[i] != 10) {
            int entrada = indice(alfabeto, secuencia[i]);
            if (estado >= 0 && entrada >= 0) {
                int *puntero = matriz + (estado * n) + entrada;
                estado = *puntero;
            } else {
                estado = -1;
                i = strlen(secuencia);
            }
        }
    }
    return esFinal(estado, finales, f);
}
// Automata ISBN   
// International Standard Book Number: estandar de 13 digitos mas 4 guiones.
// 97(8|9)-[0-9]{1,5}-[0-9]{1,7}-[0-9]{1,6}-[0-9]
char const ALFABETO_ISBN[] = "0123456789-"; 
int const MATRIZ_ISBN[][11] = {
//     0    1    2    3    4    5    6    7    8    9    -
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  Q1,  -1},  // Q0 
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  Q2,  -1,  -1,  -1},  // Q1
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  Q3,  Q3,  -1},  // Q2
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  Q4},  // Q3
    { Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  -1},  // Q4
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, Q10},  // Q5
    { Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9, Q10},  // Q6
    { Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6, Q10},  // Q7
    { Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7, Q10},  // Q8
    { Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8, Q10},  // Q9
    {Q17, Q17, Q17, Q17, Q17, Q17, Q17, Q17, Q17, Q17,  -1},  // Q10
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, Q18},  // Q11
    {Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q18},  // Q12
    {Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q18},  // Q13
    {Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q18},  // Q14
    {Q14, Q14, Q14, Q14, Q14, Q14, Q14, Q14, Q14, Q14, Q18},  // Q15
    {Q15, Q15, Q15, Q15, Q15, Q15, Q15, Q15, Q15, Q15, Q18},  // Q16
    {Q16, Q16, Q16, Q16, Q16, Q16, Q16, Q16, Q16, Q16, Q18},  // Q17
    {Q24, Q24, Q24, Q24, Q24, Q24, Q24, Q24, Q24, Q24,  -1},  // Q18
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, Q25},  // Q19
    {Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q25},  // Q20
    {Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q25},  // Q21
    {Q21, Q21, Q21, Q21, Q21, Q21, Q21, Q21, Q21, Q21, Q25},  // Q22
    {Q22, Q22, Q22, Q22, Q22, Q22, Q22, Q22, Q22, Q22, Q25},  // Q23
    {Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q25},  // Q24
    {Q26, Q26, Q26, Q26, Q26, Q26, Q26, Q26, Q26, Q26,  -1},  // Q25
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}}; // Q26
int const FINAL_ISBN[] = {Q26};
int const LEN_ISBN = 17;
int validar_isbn(char *isbn) {
    int return_code = 0;
    if (strlen(isbn) == LEN_ISBN) {
        return_code = automata((char *)ALFABETO_ISBN, (int *)MATRIZ_ISBN, strlen(ALFABETO_ISBN), 
                              (int *)FINAL_ISBN, 1, isbn);
    }
    return return_code;
}
// Automata Titulo
// Secuencia no vacia de letras, digitos decimales, signos de puntuacion. 
// Maxima longitud 40. 
// Ademas se hizo las siguientes suposiciones:
//    - Separardor el Espacio en Blanco.
//    - Debe comenzar con una letra o digito decimal.
//    - Signos de puntuacion, punto, coma, dos puntos, punto y coma, guion.
// (X|x|[0-9])(X|x| |[.,:;-]|[0-9])*
char const ALFABETO_TITULO[] = "Xx .,:;-"; // X=[A-Z],x=[a-z]
int const MATRIZ_TITULO[][18] = {
//    X   x  Esp  .   ,   :   ;   -   0   1   2   3   4   5   6   7   8   9
    {Q1, Q1, -1, -1, -1, -1, -1, -1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1},   // Q0
    {Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1, Q1},}; // Q1
int const FINAL_TITULO[] = {Q1};
int const LEN_TITULO = 40;
int validar_titulo(char *titulo) {
    int return_code = 0;
    if (!(strlen(titulo) > LEN_TITULO)) {
        return_code = automata((char *)ALFABETO_TITULO, (int *)MATRIZ_TITULO, strlen(ALFABETO_TITULO), 
                              (int *)FINAL_TITULO, 1, titulo);
	}	
    return return_code;
}
int validar_editorial(char *editorial) {
    int return_code = 0;
    if (!(strlen(editorial) > LEN_TITULO)) {
        return_code = automata((char *)ALFABETO_TITULO, (int *)MATRIZ_TITULO, strlen(ALFABETO_TITULO), 
                              (int *)FINAL_TITULO, 1, editorial);
    }
    return return_code;
}
// Automata Autor  
// Debe contener al menos un Apellido y un Nombre.  Cada uno debe ser una secuencia de
// letras que empiece con mayusculas. Puede haber abreviaturas: mayuscula seguida de 
// minusculas y termina en punto.  Tambien siglas: mayuscula y punto. Se separan con 
// espacio en blanco. Maxima longitud 30.
// Ademas se supuso que el Apellido y el nombre minimos no pueden ser abreviaturas ni siglas.
// Xxx* Xxx*( X(xx*(|.)|.))*
char const ALFABETO_NOMBRE[] = "Xx ."; // X=[A-Z],x=[a-z]
int const MATRIZ_NOMBRE[][4] = {
//    X   x  Esp  .	
    {Q1, -1, -1, -1},  // Q0
    {-1, Q2, -1, -1},  // Q1 
    {-1, Q2, Q3, -1},  // Q2
    {Q4, -1, -1, -1},  // Q3
    {-1, Q5, -1, -1},  // Q4
    {-1, Q5, Q6, -1},  // Q5 
    {Q7, -1, -1, -1},  // Q6
    {-1, Q8, -1, Q9},  // Q7	
    {-1, Q8, Q6, Q9},  // Q8
    {-1, -1, Q6, -1}}; // Q9
int const FINAL_NOMBRE[] = {Q5, Q8, Q9};
int const LEN_NOMBRE = 30;
int validar_autor(char *autor) {
    int return_code = 0;
    if (!(strlen(autor) > LEN_NOMBRE)) {
        return_code = automata((char *)ALFABETO_NOMBRE, (int *)MATRIZ_NOMBRE, strlen(ALFABETO_NOMBRE), 
                              (int *)FINAL_NOMBRE, 3, autor);
    }
    return return_code;
}
// Automata Fecha
// Formato dd/mm/aaaa
// Ademas no se valida los dias segun el mes.
// (0[1-9]|(1|2)[0-9]|3(0|1))/(0[1-9]|1(0|1|2))/[1-9][0-9]{3}
char const ALFABETO_FECHA[] = "0123456789/";  
int const MATRIZ_FECHA[][11] = {
//     0    1    2    3    4    5    6    7    8    9    /	
    { Q3,  Q1,  Q1,  Q2,  -1,  -1,  -1,  -1,  -1,  -1, -1},  // Q0 
    { Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4, -1},  // Q1
    { Q4,  Q4,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1},  // Q2
    { -1,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4, -1},  // Q3
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, Q5},  // Q4
    { Q7,  Q6,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1},  // Q5
    { Q8,  Q8,  Q8,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1},  // Q6
    { -1,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8, -1},  // Q7
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, Q9},  // Q8
    { -1, Q10, Q10, Q10, Q10, Q10, Q10, Q10, Q10, Q10, -1},  // Q9
    {Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, -1},  // Q10
    {Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, -1},  // Q11
    {Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q13, Q13, -1},  // Q12
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, -1}};  // Q13
int const FINAL_FECHA[] = {Q13};
int const LEN_FECHA = 10;
int validar_fecha(char *fecha) {
    return automata((char *)ALFABETO_FECHA, (int *)MATRIZ_FECHA, strlen(ALFABETO_FECHA), 
                          (int *)FINAL_FECHA, 1, fecha);
}
// Automata Precio
// Numero real con formato decimal, con punto para separar parte entera 
// de la fraccionaria. Con dos digitos decimales. Desde 0.01 a 99999.99
// ([0-9]|[1-9][0-9]{,4}).(0[1-9]|[1-9][0-9])
char const ALFABETO_PRECIO[] = "0123456789.";
int const MATRIZ_PRECIO[][11] = {
//	   0    1    2    3    4    5    6    7    8    9    .
    { Q1,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  -1},  // Q0 
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  Q2},  // Q1
    { Q3, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11,  -1},  // Q2
    { -1, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12,  -1},  // Q3
    { Q5,  Q5,  Q5,  Q5,  Q5,  Q5,  Q5,  Q5,  Q5,  Q5, Q10},  // Q4
    { Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6,  Q6, Q10},  // Q5
    { Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7,  Q7, Q10},  // Q6
    { Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8,  Q8, Q10},  // Q7
    { Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9,  Q9, Q10},  // Q8
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, Q10},  // Q9
    {Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11, Q11,  -1},  // Q10
    {Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12, Q12,  -1},  // Q11
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}}; // Q12
int const FINAL_PRECIO[] = {Q12};
int const LEN_PRECIO = 8;
int validar_precio(char *precio) {
    return automata((char *)ALFABETO_PRECIO, (int *)MATRIZ_PRECIO, strlen(ALFABETO_PRECIO), 
                   (int *)FINAL_PRECIO, 1, precio);
}
// Automata Cantidad
// Numero entero sin signo. Desde 1 a 9999
// [1-9][0-9]{,3}
char ALFABETO_CANTIDAD[] = "0123456789";
int MATRIZ_CANTIDAD[][10] = {
//     0    1    2    3    4    5    6    7    8    9    
    { -1,  Q1,  Q1,  Q1,  Q1,  Q1,  Q1,  Q1,  Q1,  Q1}, // Q0 
    { Q2,  Q2,  Q2,  Q2,  Q2,  Q2,  Q2,  Q2,  Q2,  Q2}, // Q1
    { Q3,  Q3,  Q3,  Q3,  Q3,  Q3,  Q3,  Q3,  Q3,  Q3}, // Q2
    { Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4,  Q4}, // Q3
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}};// Q4
int FINAL_CANTIDAD[] = {Q1, Q2, Q3, Q4};
int LEN_CANTIDAD = 4;
int validar_cantidad(char *cantidad) {
     return automata((char *)ALFABETO_CANTIDAD, (int *)MATRIZ_CANTIDAD, strlen(ALFABETO_CANTIDAD), 
                    (int *)FINAL_CANTIDAD, 4, cantidad);
}
