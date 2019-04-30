#include <iostream>
#include "List.hpp"
#include <stdlib.h>

int main() {
    List<int> l= List<int>();
    std::cout << l.size() << std::endl;
    l.insert(1);
    std::cout << l.size() << std::endl;
    l.insert(2);
    std::cout << l.size() << std::endl;
    l.append(5);

    List<int> l2= List<int>();
    l2=l;
    l= List<int>();
    std::cout << l2.size() << std::endl;

    std::cout << l.size() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}