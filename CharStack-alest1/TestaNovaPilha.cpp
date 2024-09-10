#include <iostream>
#include "CharStack.hpp"

using namespace std;

int main() {
    CharStack pilhaOriginal(50);
    pilhaOriginal.push('A');
    pilhaOriginal.push('B');
    pilhaOriginal.push('C');
    
    CharStack* pilhaCopia = pilhaCopia->copia(pilhaOriginal);
    
    // Exibe os elementos da pilha original e da pilha copiada
    char ch;
    std::cout << "Pilha Original: ";
    while (pilhaOriginal.pop(ch)) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Pilha Copiada: ";
    while (pilhaCopia->pop(ch)) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    
    delete pilhaCopia;  // Não esqueça de liberar a memória alocada
    return 0;
}