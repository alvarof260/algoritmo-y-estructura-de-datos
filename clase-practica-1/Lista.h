#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct nodo
{
    Item dato;
    struct nodo *sig;
} Nodo;

void crearLista(Nodo **h)
{
    *h = NULL;
}

int esListaVacia(Nodo *h)
{
    return h == NULL;
}

void mostrar(Nodo *l)
{
    Nodo *aux = l;
    if (esListaVacia(aux))
    {
        return;
    }
    while (aux != NULL)
    {
        printf("%d \n", aux->dato);
        aux = aux->sig;
    }
}

void primerElemento(Nodo *l)
{
    if (esListaVacia(l))
    {
        return;
    }
    printf("El primer elemento de la lista es: %d\n", l->dato);
}

void insertar(Nodo **l, Item x)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = x;
    nuevo->sig = *l;
    *l = nuevo;
}

void borrar(Nodo **l)
{
    if (esListaVacia(*l))
    {
        return;
    }
    Nodo *aux = *l;
    *l = (*l)->sig;
    free(aux);
}

int longitud(Nodo *l)
{
    int cont = 0;
    Nodo *aux = l;
    while (aux != NULL)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}

int pertenece(Nodo *l, Item x)
{
    Nodo *aux = l;
    while (aux != NULL)
    {
        if (aux->dato == x)
        {
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
}

// inserta un valor dado en la posición K-ésima de la lista si es que existe, caso contrario 
// se inserta al final.
void insertarK(Nodo **l, Item x, int k)
{
    if(k == 0)
    {
        insertar(l,x);
        return;
    }
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = x;
    Nodo *aux = *l;
    for (int i = 0; i < k - 1; i++)
    {
        if (aux == NULL)
        {
            return;
        }
        aux = aux->sig;
    }
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
}