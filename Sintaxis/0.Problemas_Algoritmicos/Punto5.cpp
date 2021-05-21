#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Protipos de funciones:
void end();

main()
{
	char frase[100],palabra[30];
    
    printf("\nIngrese una frase: ");
    _flushall();
    gets(frase);
    system("cls");

    printf("\nIngrese la palabra que desea buscar: ");
    gets(palabra);

    if (strstr(frase,palabra) == NULL)
    {
        printf("\nLa palabra buscada no se encuentra.");
    }
    else
    {
        printf("\nLa palabra buscada se encuentra en la frase.");
    }
        
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