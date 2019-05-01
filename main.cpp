#include <iostream>
#include "List.hpp"
#include "Person.hpp"
#include <stdlib.h>

int main() {
    /*
     * First we test with the given output wanted.
     */
    List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    const List<int> c = { 42, 3, 14 };
    for (List<int>::ConstIterator it = c.end(); it != c.begin(); --it)
        cout << *it << " ";
    cout << endl;

    /*
     * Now we want to test with the custom Person class created alongside this
     * project.
     */
    List<Person> l2;
    l2.append(*new Person("test un"));
    l2.append(*new Person("test deux"));
    l2.append(*new Person("test trois"));
    for (List<Person>::Iterator it = l2.begin(); it != l2.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    //===========================================

    List<int> l3= List<int>();
    std::cout << l.size() << std::endl;
    l3.insert(1);
    std::cout << l.size() << std::endl;
    l3.insert(2);
    std::cout << l.size() << std::endl;
    l3.append(5);

    List<int> l4= List<int>();
    l4=l3;
    l3= List<int>();
    std::cout << l3.size() << std::endl;

    std::cout << l.size() << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}