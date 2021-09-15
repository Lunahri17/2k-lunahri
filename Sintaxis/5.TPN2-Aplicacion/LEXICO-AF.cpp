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
#define Q9 9
#define Q10 10

int matriz[6][7] = {
    //0   1   2   3   4   5   6
    { -1, Q1,  Q2,  Q3,  Q4, Q10, Q10}, // Q0
    { Q1, -1,  Q5,  Q5,  Q5,  Q5, Q10}, // Q1
    {Q10, Q7, Q10,  Q7,  Q7, Q10, Q10}, // Q2
    {Q10, Q9,  Q9, Q10,  Q9, Q10, Q10}, // Q3
    {Q10, Q8,  Q8,  Q8, Q10, Q10, Q10}, // Q4
    { Q5, -1,  Q6,  Q6,  Q6, Q10, Q10}, // Q5
};

int FINALES[] = {Q6, Q7, Q8, Q9, Q10);

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

int conversor(char caracter) {
    return  (isdigit(caracter) ? 0 :
             (caracter == '1','2','3','4','7','8','9') ? 1 :
             (caracter == '+','-') ? 2 :
             (caracter == '*','/') ? 3 :
             (caracter == '(',')') ? 4:
             (caracter == '.') ? 5 : 6);
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

        char tokenType[][20] = {
            "ENTERO",
            "REAL",
            "PARENTESIS",
            "OPERADORES",
            "ERROR"
        };
        int OFFSET = 7;

        FILE *handler1 = fopen(entrada, "r+w");
        if (handler1 != NULL) {
            char expresion[200] = "";
            char cadena[100];
            while (fgets(cadena, 100, handler1) != NULL) {
                strcat(expresion, cadena);
            }
            strcat(expresion, " "); 
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
