#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>

//Estructuras:
struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct libro
{
	double isbn;
	char tituloObra[41];
	char apeNom[31];
	char nomEditorial[41];
	fecha fechaPublicacion;
	float precio;
	int cantidad;
};



//Protipos de funciones:
void end();
int cargarDatos(libro regLibros[200]);
bool comprobarISBN(libro regLibros[200],int numLibros,double isbn);
void cargarRegistro(libro regLibros[200],int numLibros,double isbn);
char cargarTitulo();

//Variables globales:


main()
{
	libro regLibros[200];
	int numLibros = 0;
	double isbn;
	bool stop = false;

	numLibros = cargarDatos(regLibros);

	if (numLibros != -1)
	{
		do
		{
			printf("\nIngrese el ISBN: ");
			scanf("%lf",&isbn);
			if (isbn>1000000000000 and isbn<10000000000000) {
				if (comprobarISBN(regLibros,numLibros,isbn)==false) {	
					stop = true;
				}
			} else {
				printf("\nIngresó un ISBN incorrecto, vuelva a intentarlo");
			}
		} while (!stop);
		
		cargarRegistro(regLibros,numLibros,isbn);
	}
	
	
	end();
}

int cargarDatos(libro regLibros[200]){
	FILE *arch;
    int i = 0;
    
    arch=fopen("Libros.dat","a+");

    if (arch==NULL)
    {
        printf("\nNo fue posible creear, o leer, el archivo 'Libros.dat', contacte con soporte.");
		return -1;
    }
    else
    {
		rewind(arch);

        fread(&regLibros[i],sizeof(libro),1,arch);
        while (!feof(arch))
        {
            i++;
            fread(&regLibros[i],sizeof(libro),1,arch);
        }
        fclose(arch);
		return i;
    }
}

bool comprobarISBN(libro regLibros[200],int numLibros,double isbn){
	bool esta;

	do {
		esta = false;

		for (int i = 0; i < numLibros; i++) {
			if (regLibros[i].isbn == isbn) {
				esta = true;
				break;
			}
		}

		if (esta) {
			printf("\nYa existe el ISBN que ingreso, vuelva a intentarlo.");
		}
	} while (esta);

	return esta;
}

void cargarRegistro(libro regLibros[200],int numLibros,double isbn){

	regLibros[numLibros].isbn = isbn;
	regLibros[numLibros].tituloObra = cargarTitulo();
	
}

char cargarTitulo(){
	char titulo[41];

	do
	{
		printf("\nIngrese un titulo: ");
		gets(titulo);
		if (strlen(titulo) > 40 or strlen(titulo) == 0)
		{
			printf("\nEl nombre del titulo debe ser menor o igual a 40 caracteres, y no nulo. Vuelva a intentarlo");
		}
	} while (strlen(titulo) > 40 or strlen(titulo) == 0);
	
	return titulo;
}

void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}