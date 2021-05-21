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
	char isbn[18];
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
bool comprobarISBN(libro regLibros[200],int numLibros,char isbn[18]);
void cargarRegistro(libro regLibros[200],int &numLibros,char isbn[18]);
void cargarTitulo(char titulo[41]);
void cargarApeNom(char apeNom[31]);
bool verificarCaracteres(char apeNom[31]);
void cargarEditorial(char Editorial[41]);
void cargarFecha(fecha fechaAux);
float cargarPrecio();
int cargarCantidad();
void guardarArchivo(libro regLibros[200],int numLibros);

//Variables globales:


main()
{
	libro regLibros[200];
	int numLibros = 0;
	char isbn[18];
	bool stop = false;
	
	//Carga los registros del archivo a memoria, y obtiene el numero de registros existentes.
	numLibros = cargarDatos(regLibros);

	if (numLibros != -1)
	{
		printf("\n\t---Alta sobre datos de libros---\n");

		do
		{
			printf("\n Ingrese el ISBN: ");
			_flushall;
			gets(isbn);

			//Verifica si el isb es correcto.
			if (strlen(isbn) == 17) {
				
				if ((isbn[0] == '9') and (isbn[1] == '7') and (isbn[2] == '8' or isbn[2] == '9')) {
					
					//Aquí comprueba si ya existe algún ISBN en los registros cargados.
					if (comprobarISBN(regLibros,numLibros,isbn)==false) {	
						stop = true;
					}					
				}
			}
			
			if (!stop) {
				printf("\n\t--- Ingreso un ISBN incorrecto, vuelva a intentarlo. ---\n");
			}
		} while (!stop);
		
		//Carga los registros.
		cargarRegistro(regLibros,numLibros,isbn);

		//Guarda los registros en archiivos.
		guardarArchivo(regLibros,numLibros);
		printf("\n\n--- Su libro fue guardado con exito. ---");
	}

	end();
}

int cargarDatos(libro regLibros[200]) {
	FILE *arch;
    int i = 0;
    
    arch=fopen("Libros.dat","a+b");

    if (arch == NULL)
    {
        printf("\n\t --- No fue posible creear, o leer, el archivo 'Libros.dat', contacte con soporte. ---\n");
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

bool comprobarISBN(libro regLibros[200],int numLibros,char isbn[18]) {
	bool esta = false;

	for (int i = 0; i < numLibros; i++) {
		if (strcmp(regLibros[i].isbn,isbn) == 0) {
			esta = true;
			break;
		}
	}

	if (esta) {
		printf("\n\t--- Ya existe el ISBN que ingreso, vuelva a intentarlo. ---\n");
	}

	return esta;
}

void cargarRegistro(libro regLibros[200],int &numLibros,char isbn[18]) {
	char charAux[41],apeNom[31];
	fecha fechaAux;

	strcpy(regLibros[numLibros].isbn,isbn);
	
	cargarTitulo(charAux);
	strcpy(regLibros[numLibros].tituloObra,charAux);
	
	cargarApeNom(apeNom);
	strcpy(regLibros[numLibros].apeNom,apeNom);
	
	cargarEditorial(charAux);
	strcpy(regLibros[numLibros].nomEditorial,charAux);
	
	cargarFecha(fechaAux);
	
	regLibros[numLibros].fechaPublicacion = fechaAux;
	
	regLibros[numLibros].precio = cargarPrecio();

	regLibros[numLibros].cantidad = cargarCantidad();

	numLibros++;
}

void cargarTitulo(char titulo[41]) {
	do
	{
		printf("\n Ingrese un titulo: ");
		_flushall;
		gets(titulo);
		if (strlen(titulo) > 40 or strlen(titulo) == 0)
		{
			printf("\n\t--- El nombre del titulo debe ser menor o igual a 40 caracteres, y no nulo. Vuelva a intentarlo. ---\n");
		}
	} while (strlen(titulo) > 40 or strlen(titulo) == 0);
}

void cargarApeNom(char apeNom[31]) {
	bool stop;

	do
	{
		stop = true;
	
		printf("\n Ingrese un Apellido y Nombre: ");
		_flushall;
		gets(apeNom);

		if (strlen(apeNom) > 30 or strlen(apeNom) == 0)
		{
			printf("\n\t--- El Apellido y Nombre debe ser menor o igual a 30 caracteres, y no nulo. Vuelva a intentarlo. ---\n");
			stop = false;
		}
		if (verificarCaracteres(apeNom) == false)
		{
			printf("\n\t--- Cada cadena del Apellido y Nombre debe empezar con una mayuscula. Vuelva a intentarlo. ---\n");
			stop = false;
		}
		
	} while (!stop);
}

bool verificarCaracteres(char apeNom[31]) {
	bool esValido = false;

	for (int i = 0; i < strlen(apeNom); i++)
	{	
		if (i == 0) {
			if (apeNom[i]>='A' and apeNom[i]<='Z')
			{
				esValido = true;
			}
		}
		
		if (apeNom[i]==' ')
		{
			if (apeNom[i+1]>='A' and apeNom[i+1]<='Z')
			{
				esValido = true;
			} else {
				esValido = false;
				break;
			}
		} 
	}
	
	return esValido;
}

void cargarEditorial(char Editorial[41]) {
	do
	{
		printf("\n Ingrese el Nombre de la Editorial: ");
		_flushall;
		gets(Editorial);
		if (strlen(Editorial) > 40 or strlen(Editorial) == 0)
		{
			printf("\n\t--- El Nombre de la Editorial debe ser menor o igual a 40 caracteres, y no nulo. Vuelva a intentarlo. ---\n");
		}
	} while (strlen(Editorial) > 40 or strlen(Editorial) == 0);
}

void cargarFecha(fecha fechaAux) {
	bool stop = false;

	do
	{
		printf("\n Ingrese la fecha de publicacion:");
		printf("\n Dia: ");
		scanf("%d",&fechaAux.dia);
		printf("\n Mes: ");
		scanf("%d",&fechaAux.mes);
		printf("\n Anio: ");
		scanf("%d",&fechaAux.anio);

		if (fechaAux.dia >= 1 and fechaAux.dia <= 30)
		{
			if (fechaAux.mes >= 1 and fechaAux.mes <= 12)
			{
				stop = true;
			}
		}
		
		if (!stop)
		{
			printf("\n\t--- Ingreso una fecha no valida. Vuelva a intentarlo. ---\n");
		}
	} while (!stop);
}

float cargarPrecio() { 
	float aux;
	bool stop = false;

	do
	{
		printf("\n Ingrese el precio: ");
		scanf("%f",&aux);
		
		if (aux > 0 and aux <= 99999.99)
		{
			stop = true;
		}
		else
		{
			printf("\n\t--- Ingreso un precio no valido. Vuelva a intentarlo. ---\n");
		}
	} while (!stop);

	return aux;
}

int cargarCantidad() {
	int aux;
	bool stop = false;

	do
	{
		printf("\n Ingrese la cantidad de libros: ");
		scanf("%d",&aux);
		
		if (aux > 0 and aux <= 9999)
		{
			stop = true;
		}
		else
		{
			printf("\n\t--- Ingreso una cantidad no valida. Vuelva a intentarlo. ---\n");
		}
	} while (!stop);

	return aux;
}

void guardarArchivo(libro regLibros[200],int numLibros)
{
    FILE *arch;
    arch =  fopen("Libros.dat","w+b");

    for (int i = 0; i < numLibros; i++)
    {

        fwrite(&regLibros[i],sizeof(libro),1,arch);
    }
	fclose(arch);
}

void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}