#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Protipos de funciones:
void end();

main()
{
	char palabra[70],palabra_inv[70];
    
    printf("\nIngrese la palabra: ");
    _flushall();
    gets(palabra);

    strcpy(palabra_inv,palabra);
    strrev(palabra_inv);
    
    printf("\nLa palabra invertida es: ");
    puts(palabra_inv);
    
	end();
}

void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}