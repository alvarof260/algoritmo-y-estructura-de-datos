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

void borrar(Lista *l)
{
    if (esListaVacia(*l))
        return;
    Nodo* actual = *l;
    *l = (*l)->sig;
    delete actual;
}

int longitud(Lista l)
{
    int i = 0;
    while (l != NULL)
    {
        i++;
        l = l->sig;
    }
    return i;
}

int pertenece(Lista l,Item dato)
{
    if (esListaVacia(l))
        return 0;
    while (l != NULL)
    {
        if(dato == l->dato)
            return 1;
        l = l->sig;
    }
    return 0;
}

void insertarK(Nodo** l, Item x, int k)
{
     if (k == 0)
    {
        insertar(l, x);
        return;
    }

    Nodo* nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = nullptr; // Establecer el siguiente nodo del nuevo nodo como nullptr

    Nodo* aux = *l;
    int contador = 0;
    while (aux != nullptr && contador < k - 1)
    {
        aux = aux->sig;
        contador++;
    }

    if (aux == nullptr)
    {
        std::cerr << "La posición está más allá del final de la lista." << std::endl;
        delete nuevo; // Liberar memoria del nuevo nodo antes de salir
        return;
    }

    nuevo->sig = aux->sig;
    aux->sig = nuevo;
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

