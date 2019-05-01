//
// Created by guillaume on 01/05/19.
//

#ifndef FURRY_WAFFLE_PERSON_HPP
#define FURRY_WAFFLE_PERSON_HPP

#include <string>

using namespace std;

/**
 * Simple class representing a person for testing reasons.
 */
class Person {
private:
    string name;

public:

    /**
     * Constructor of a person
     * @param n the name of the person
     */
    Person(string n){
        this->name = n;
    }

    /**
     * Method to string
     * @return the name of the person
     */
    string toString(){
        return name;
    }

    ostream& operator<<(ostream& os)
    {
        return os << name;
    }
};
#endif //FURRY_WAFFLE_PERSON_HPP
