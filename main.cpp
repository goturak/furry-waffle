#include <iostream>
#include "List.hpp"
#include "Person.hpp"
#include <stdlib.h>

int main() {

    //Testing empty constructor as well as << and size() on empty list
    List<int> listInt= List<int>();
    cout<<"listInt = "<<listInt;
    cout<<"listInt size = "<<listInt.size()<<endl<<endl;


    cout<<"appending and inserting stuff"<<endl;
    //testing insert and append
    listInt.append(3);
    listInt.append(4);
    listInt.insert(2);
    listInt.insert(1);

    cout<<"listInt = "<<listInt;
    cout<<"listInt size = "<<listInt.size()<<endl<<endl;


    cout<< "copying listInt to listIntCopy"<<endl;
    //testing copy constructor
    List<int> listIntCopy= List<int>(listInt);
    cout<<"listIntCopy = "<<listIntCopy;
    cout<<"listIntCopy size = "<<listIntCopy.size()<<endl<<endl;


    //testing removeAt and remove

    listInt.removeAt(1);
    listInt.removeAt(2);
    cout<<"listInt after removeAt(1) and removeAt(2) = "<<listInt;

    listIntCopy.remove(3);
    cout<<"listIntCopy after remove(3) = "<<listIntCopy<<endl;

    cout<<"listIntCopy[1] = "<<listIntCopy[1]<<endl;

  /*
   * First we test with the given output wanted.
   */
  /*List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
  for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
       cout << *it << " ";
    cout << endl;
    cout << l.find("trois");
    cout << endl;
    cout << l.find("quatre");
    cout << endl;

    List<string> lCopy=  List<string>(l);

  const List<int> c = { 42, 3, 14 };
  for (List<int>::ConstIterator it = c.begin(); it != c.end(); ++it)
       cout << *it << " ";
    cout << endl;
    cout << l << endl<< lCopy;

    /*
     * Now we want to test with the custom Person class created alongside this
     * project.
     */
  /*List<Person> l2=List<Person>();
    l2.append(Person("test un"));
    l2.append(Person("test deux"));
    l2.append(Person("test trois"));

  List<Person> l2copy=List<Person>(l2);
    for (List<Person>::Iterator it = l2.begin(); it != l2.end(); ++it)
        cout << (*it).toString()<< " ";
    cout << endl;

    cout<< l2copy;
    //===========================================

    List<int> l3= List<int>();
    std::cout << l3.size() << std::endl;
    l3.insert(1);
    std::cout << l3.size() << std::endl;
    l3.insert(2);

    std::cout << l3.size() << std::endl;
    l3.append(0);

  l3.append(4);
    List<int> l4= List<int>(l3);

   // l3= List<int>();

  l3.remove(4);

    std::cout << l3.size() << std::endl;

    std::cout << "Hello, World!" << std::endl;


        cout << l3<< endl<<l4;

  cout << endl;

  cout<< l3[2];
    return 0;*/
}