#include <iostream>
#include "List.hpp"
#include <stdlib.h>

int main() {
    List<int> l= List<int>();


    std::cout << l.size() << std::endl;
    l.append(1);
    std::cout << l.size() << std::endl;
    l.append(2);
    std::cout << l.size() << std::endl;
    l.append(5);

    List<int> l2= List<int>();
    l2=l;
    //l= List<int>();
    std::cout << l2.size() << std::endl;

    std::cout << l.size() << std::endl;
    std::cout << "Hello, World!" << std::endl;

    for (List<int>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";

    return 0;
}