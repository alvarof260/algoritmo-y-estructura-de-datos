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
    std::cout << "la longitud es: " << longitud(head)<< std::endl;
    std::cout << "el primer elemento es: " << primerElemento(head)<< std::endl;
    borrar(&head);
    pertenece(head, 50)
        ? std::cout << "Pertenece\n" << std::endl
        : std::cout << "No Pertenece\n" << std::endl;
    insertarK(&head, 200, 1);
    insertarK(&head, 250, 90);
    mostrar(head);
    liberarMemoria(&head);
    return 0;
}