#include <iostream>
#include "TDA_Lista_Circular_Doble.h"

int main()
{
    TDA_Lista_Circular_Doble<int> l;

    std::cout << "=== Insertando al final ===" << std::endl;
        std::cout << "Insertando 1..." << std::endl; 
        std::cout << "Insertando 4..." << std::endl; 
        std::cout << "Insertando 7...\n" << std::endl;

    l.insertLast(1);
    l.insertLast(4);
    l.insertLast(7);
    
    std::cout << "=== Insertando al principio ===" << std::endl;
        std::cout << "Insertando 2..." << std::endl;
        std::cout << "Insertando 6..." << std::endl;
        std::cout << "Insertando 5...\n" << std::endl;

    l.insertFirst(2);
    l.insertFirst(6);
    l.insertFirst(5);

    std::cout << "=== Insertar despues de un nodo ===" << std::endl;
        std::cout << "Insertando despues 9 de 2..." << std::endl;
        std::cout << "Insertando 0 despues del nodo en la segunda posicion...\n" << std::endl;

    l.insertAfter(l.search(2), 9);
    l.insertAfter(l.get(1), 0);

    std::cout << "=== Eliminando un nodo ===" << std::endl;
        std::cout << "Eliminando el numero 5...\n" << std::endl;

    l.deleteNode(5);

    std::cout << "=== Imprimiendo hacia enfrente (despues de head) ===" << std::endl;
    l.printForward();
    std::cout << "\n";

    std::cout << "=== Imprimiendo hacia atras (head y antes) ===" << std::endl;
    l.printBackwards();
    std::cout << "\n";

    std::cout << "=== Tamaño de la lista ===" << std::endl;
    std::cout << "La lista tiene: " << l.getSize() << " nodos" << std::endl;

    return 0;
}
