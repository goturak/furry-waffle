#include <iostream>
#include "List.h"
#include <stdlib.h>

int main() {
    List<int>* l= new List<int>();
    std::cout << l->size() << std::endl;
    l->insert(1);
    std::cout << l->size() << std::endl;
    l->insert(2);
    std::cout << l->size() << std::endl;
    l->append(5);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}