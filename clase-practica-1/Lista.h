#include <stdio.h>

typedef int Item;

struct Nodo
{
    Item dato;
    struct Nodo *sig;
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


