#include <iostream>
#include "List.h"
#include <stdlib.h>

int main() {
    List<int>* l= new List<int>();
    l->insert(1);
    l->insert(2);

    l->append(5);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}