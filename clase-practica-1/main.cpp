#include <iostream>
#include "Lista.h"

int main()
{
    Lista head;
    crearLista(&head);
    esListaVacia(head) 
        ? std::cout << "Lista Vacia!\n" << std::endl 
        : std::cout << "Lista no vacia!\n" << std::endl;
    insertar(&head, 50);
    insertar(&head, 100);
    insertar(&head, 20);
    mostrar(head);
    std::cout << "el primer elemento es: " << primerElemento(head)<< std::endl;
    liberarMemoria(&head);
    return 0;
}