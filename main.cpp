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
  for (List<int>::ConstIterator it = c.begin(); it != c.end(); ++it)
       cout << *it << " ";
    cout << endl;

    /*
     * Now we want to test with the custom Person class created alongside this
     * project.
     */
  List<Person> l2=List<Person>();
    l2.append(Person("test un"));
    l2.append(Person("test deux"));
    l2.append(Person("test trois"));
    for (List<Person>::Iterator it = l2.begin(); it != l2.end(); ++it)
        cout << (*it).toString()<< " ";
    cout << endl;
    //===========================================

    List<int> l3= List<int>();
    std::cout << l3.size() << std::endl;
    l3.insert(1);
    std::cout << l3.size() << std::endl;
    l3.insert(2);

    std::cout << l3.size() << std::endl;
    l3.append(0);

  l3.append(4);
    List<int> l4= List<int>();
    l4=l3;
   // l3= List<int>();

  l3.remove(0);

    std::cout << l3.size() << std::endl;

    std::cout << "Hello, World!" << std::endl;

    for (List<int>::Iterator it = l3.begin(); it != l3.end(); ++it)
        cout << *it << " ";

  cout << endl;

  cout<< l3[2];
    return 0;
}