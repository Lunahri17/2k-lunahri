#include<stdio.h>
#include<stdlib.h>

//Estructuras:
struct nodo{
	int nro;
    nodo *sgte;
};

//Protipos de funciones:
void end();
void insertar_lista(nodo *&Lista,int valor);
void buscar_nodo(nodo *&Lista,int valor);

main()
{
	nodo *Lista = NULL;
    int n,valor;

    printf("\nIngrese el tamanio de la lista: ");
    scanf("%d",&n);

    //Carga la lista:
    for (int i = 0; i < n; i++)
    {
        printf("\nIngrese el numero entero %d: ",i+1);
        scanf("%d",&valor);
        insertar_lista(Lista,valor);
    }
    
    printf("\nIngrese el numero que desea buscar: ");
    scanf("%d",&valor);
    buscar_nodo(Lista,valor);
	
	end();
}

void insertar_lista(nodo *&Lista,int valor)
{
	nodo *nuevo_nodo = new(nodo); //pide un nuevo nodo.
	
    nuevo_nodo->nro = valor;
	
    nodo *aux = Lista,*aux2;

    while ((aux != NULL) and (aux->nro < valor))
    {
        aux2 = aux;
        aux = aux->sgte;
    }
    
    if (Lista == aux)
    {
        Lista = nuevo_nodo;
    }
    else
    {
        aux2->sgte = nuevo_nodo;
    }
    
    nuevo_nodo->sgte = aux;
}

void buscar_nodo(nodo *&Lista,int valor)
{
    if (Lista!=NULL)
    {
        nodo *aux_buscar=Lista;
        nodo *anterior=NULL;

        while((aux_buscar!=NULL) and (aux_buscar->nro!=valor))
        {	
            anterior=aux_buscar;
            aux_buscar=aux_buscar->sgte;
        }

        (aux_buscar!=NULL) ? printf("\nPertenece a la lista.") : printf("\nNo pertenece a la lista.");
    }
}

void end()
{
	printf("\n\n");
	system("pause");
    printf("\n\tGracias por utilizar el programa.");
 	printf("\n\n");
	system("pause");
}