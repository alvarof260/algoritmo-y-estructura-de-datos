#include <iostream>
#include "Lista.h"

int main()
{
    Lista head;
    crearLista(head);
    esListaVacia(head) 
        ? std::cout << "Lista Vacia!\n" << std::endl 
        : std::cout << "Lista no vacia!\n" << std::endl;
    return 0;
}