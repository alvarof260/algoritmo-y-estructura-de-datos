#include <stdio.h>
#include <iostream>

typedef int Item;

struct Nodo
{
    Item dato;
    Nodo *sig;
} typedef Nodo;

typedef struct Nodo* Lista;

void crearLista(Lista *l)
{
    *l = NULL;
}

int esListaVacia(Lista l)
{
    return l == NULL;
}

void mostrar(Lista l)
{
    while (l != NULL)
    {
        std::cout << l->dato << std::endl;
        l = l->sig;
    }
}

void insertar(Lista *l, Item dato)
{
    Nodo* nuevoNodo = new Nodo{dato, NULL};
    nuevoNodo->sig = *l;
    *l = nuevoNodo;
}

Item primerElemento(Lista l)
{
    if(esListaVacia(l)) 
        return -1;
    return l->dato;
}

void liberarMemoria(Lista *l)
{
    Nodo* temp;
    while (l != NULL)
    {
        temp = *l;
        *l = (*l)->sig;
        delete temp;
    }
}

