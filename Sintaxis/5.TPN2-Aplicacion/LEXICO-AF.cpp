//Dise~ar un analizador lexico que reconozca palabras formadas por letras minusculas, 
//palabras que comienzan con una mayuscula y puede estar seguida por una o mas minusculas 
//y secuencias de dï¿½gitos. Separadas por espacios.
//Se consideraria error lexico cualquier otra secuencia que no se ajuste a las anteriores.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define Q5 5
#define Q6 6
#define Q7 7
#define Q8 8

int matriz[5][5] = {
    {Q1, Q2, Q3, Q0, Q4},
    {Q1, Q4, Q4, Q5, Q4},
    {Q4, Q2, Q4, Q6, Q4},
    {Q4, Q3, Q4, Q7, Q4},
    {Q4, Q4, Q4, Q8, Q4},
};

int FINALES[] = {Q5, Q6, Q7, Q8};

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

//0: 0..9
//1: a..z
//2: A..Z
//3: espacio
//4: cualquier otro caracter

int conversor(char caracter) {
    return ( isdigit(caracter) ? 0 :
            (islower(caracter) ? 1 :
            (isupper(caracter) ? 2 :
            (caracter == ' ') ? 3 : 4)));
}


int main(int argc, char** argv) {
    int exit_code = EXIT_SUCCESS;
    if (argc < 3) {
        printf("Error: Faltan nombres de los archivos a procesar.\n");
        exit_code = EXIT_FAILURE;
    } else {
        char entrada[30];
        strncpy(entrada, argv[1], sizeof (entrada));
        char salida[30];
        strncpy(salida, argv[2], sizeof (salida));

        char tokenType[][10] = {
            "DIGITO",
            "MINUSCULA",
            "MAYUSCULA",
            "ERROR"
        };
        int OFFSET = 5;

        FILE *handler1 = fopen(entrada, "r");
        if (handler1 != NULL) {
            char expresion[200] = "";
            char cadena[100];
            while (fgets(cadena, 100, handler1) != NULL) {
                strcat(expresion, cadena);
            }
            strcat(expresion, " "); // Se agrega un espacio para garantizar la detección del último Token
            fclose(handler1);

            FILE *handler2 = fopen(salida, "w");
            if (handler2 != NULL) {
                char lexema[50] = "";
                int estado = Q0;
                for (int i = 0; i < strlen(expresion); ++i) {
                    estado = matriz[estado][conversor(expresion[i])];
                    if (!esFinal(estado, (int *) FINALES, sizeof FINALES)) {
                        strncat(lexema, &expresion[i], 1);
                    } else {
                        fprintf(handler2, "%s %s \n", lexema, tokenType[estado - OFFSET]);
                        estado = Q0;
                        lexema[0] = '\0';
                    }
                }
                perror("proceso finalizado correctamente  \n");
                fclose(handler2);
            } else {
                perror("Error al abrir archivo de salida");
                exit_code = EXIT_FAILURE;
            }
        } else {
            perror("Error al abrir archivo de entrada");
            exit_code = EXIT_FAILURE;
        }
    }
    return exit_code;
}
