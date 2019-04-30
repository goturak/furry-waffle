#include <iostream>
#include "List.hpp"
#include <stdlib.h>

int main() {
    List<int>* l= new List<int>();
    std::cout << l->size() << std::endl;
    l->insert(1);
    std::cout << l->size() << std::endl;
    l->insert(2);
    std::cout << l->size() << std::endl;
    l->append(5);
    List<int> l2 ={4,3,2,1};
    for (List<string>::Iterator it = l->begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}