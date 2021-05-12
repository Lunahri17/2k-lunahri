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
void cargarTitulo(char *titulo);
void cargarApeNom(char *apeNom);
bool verificarCaracteres(char *apeNom);


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

int cargarDatos(libro regLibros[200]) {
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

bool comprobarISBN(libro regLibros[200],int numLibros,double isbn) {
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

void cargarRegistro(libro regLibros[200],int numLibros,double isbn) {
	char charAux[41],apeNom[31];

	regLibros[numLibros].isbn = isbn;
	cargarTitulo(charAux);
	strcpy(regLibros[numLibros].tituloObra,charAux);
	cargarApeNom(apeNom);
	strcpy(regLibros[numLibros].apeNom,apeNom);
	
}

void cargarTitulo(char *titulo) {
	do
	{
		_flushall;
		printf("\nIngrese un titulo: ");
		gets(titulo);
		if (strlen(titulo) > 40 or strlen(titulo) == 0)
		{
			printf("\nEl nombre del titulo debe ser menor o igual a 40 caracteres, y no nulo. Vuelva a intentarlo");
		}
	} while (strlen(titulo) > 40 or strlen(titulo) == 0);
}

void cargarApeNom(char *apeNom) {
	bool stop;

	do
	{
		stop = true;
	
		_flushall;
		printf("\nIngrese un Apellido y Nombre: ");
		gets(apeNom);

		if (strlen(apeNom) > 30 or strlen(apeNom) == 0)
		{
			printf("\nEl Apellido y Nombre debe ser menor o igual a 30 caracteres, y no nulo. Vuelva a intentarlo");
			stop = false;
		}
		if (!verificarCaracteres(apeNom))
		{
			printf("\nCada cadena del Apellido y Nombre debe empezar con una mayuscula. Vuelva a intentarlo");
			stop = false;
		}
		
	} while (!stop);
}

bool verificarCaracteres(char *apeNom) {
	bool esValido = false;

	for (int i = 0; i < strlen(apeNom); i++)
	{
		if (i==0 and apeNom[i]>='A' and apeNom[i]<='Z')
		{
			esValido = true;
		}
		
		if ( !( apeNom[i]==32 and (apeNom[i+1]>64 and apeNom[i+1]<91) ) )
		{
			esValido = false;
		}
	}
	
	return esValido;
}



void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}