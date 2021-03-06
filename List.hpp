//
// Created by goturak on 30/04/19.
//

#ifndef LABO3CPP_LIST_H
#define LABO3CPP_LIST_H

#include <cstdlib>

#include <iostream>

using namespace std;


template <typename T>
class List {

    struct node
    {
        T elem;
        node* prev;
        node* next;
        node(T t, node* p, node* n) : elem(t), prev(p), next(n) {}

    };


    node nullNodeTail= node( T() , nullptr, nullptr);

    node* head;
    node* tail;


    size_t length;

private:
    /**
     * Generic private class representing an iterator, that will have two children.
     */
    class GenericIterator{
    protected:
        /**
         * The value on which the iterator currently is.
         */
        node* value;
    public:

        /**
         * Overload of the == operator
         * @param it The other iterator
         * @return true if both iterator are on the same element, false otherwise.
         */
        bool operator==(GenericIterator it){
            return value == it.value;
        }


        /**
         * Overload of the != operator
         * @param it The other iterator
         * @return flase if both iterator are on the same element, true otherwise.
         */
        bool operator!=(GenericIterator it){
            return value != it.value;
        }
    };

public:

    /**
     * Iternal class representing an Iterator, inheritated from Generic Iterator
     */
    class Iterator :public GenericIterator{
    public:
        /**
         * Constructor of an Iterator
         * @param n the current node on which the iterator is.
         */
        Iterator(node* n){
            GenericIterator::value = n;
        }

        /**
         * Overload of the ++ operator.
         * @return the next value of the list.
         */
        T& operator++(){
            GenericIterator::value = GenericIterator::value->next;
            return GenericIterator::value->elem;
        }

        /**
         * Overload of the -- operator.
         * @return the previous value of the list.
         */
        T& operator--(){
            GenericIterator::value = GenericIterator::value->prev;
            return GenericIterator::value->elem;
        }

        /**
         * Overload of the -> operator.
         * @return the pointer on the value of the list.
         */
        T& operator->(){
            return GenericIterator::value->elem;
        }

        /**
         * Overload of the * operator.
         * @return the value of the list.
         */
        T operator*(){
            return GenericIterator::value->elem;
        }
    };


    /**
     * Internal class representing a const Iterator,
     * inheritated from Generic Iterator
     */
    class ConstIterator : public GenericIterator{
    public:
        /**
         * Constructor of const iterator
         * @param n the current node
         */

        ConstIterator(node* n) {
            GenericIterator::value = n;
        }

        /**
         * Overload of the ++ operator.
         * @return the next value of the list (const).
         */
        const T& operator++(){
            GenericIterator::value = GenericIterator::value->next;
            const T& v = GenericIterator::value->elem;
            return v;
        }

        /**
         * Overload of the -- operator.
         * @return the previous value of the list (const).
         */
        const T& operator--(){
            GenericIterator::value = GenericIterator::value->prev;
            const T& v =GenericIterator::value->elem;
            return v;
        }

        /**
         * Overload of the -> operator.
         * @return the pointer on the value of the list (const).
         */
        const T& operator->() const{
            const T& v = GenericIterator::value->elem;
            return v;
        }

        /**
         * Overload of the * operator.
         * @return the value of the list (const).
         */
        const T operator*() const{
            const T v = GenericIterator::value->elem;
            return v;
        }

    };






public:
    List() : head(nullptr ), tail (&nullNodeTail ),length(0) {}


    List(const List& l):head(nullptr), tail(&nullNodeTail),length(0){
        for (List<T>::ConstIterator it = l.begin(); it != l.end(); ++it)
            append(*it);


    }



    /**
     * constructor with initializer list
     * @param args initializer list
     */
    List(std::initializer_list<T> args)
            : head(nullptr), tail(&nullNodeTail),length(0) {
        int i = 0;
        for (const T *val = args.begin(); val != args.end(); ++val)
            append(*val);

    }

    /**
     * returns the element at index or throws an exception if the index is out of bounds
     * @param i index
     * @return
     */
    T operator[](int i) const{
        if(i>=size()||i<0){
            throw "Index out of bounds" ;
        }

        List<T>::ConstIterator val = begin();

        for(int j = 0; j<i;j++){
            ++val;
        }
        return *val;

    }

    /**
     * overloads assignement operator (=)
     * @param t
     */
    void operator=(List<T> t){
        head=t.head;
        tail=t.tail;
    }



    friend ostream& operator<<(ostream& os, const List<T> &list)
    {
        os << "[";
        for (int i =0; i< list.size();i++) {
            os << list[i];
            if(i != list.size()-1){
                os << ",";
            }
        }
        os << "]" << endl;
        return os;
    }

    /**
     *
     * @return if the list is empty or not
     */
    bool empty() const { return ( !head ); }


    /**
     * removes the element at index or throws an exception if the index is out of bounds
     * @param index
     */
    void removeAt(size_t index){
        if(index>=size()){
            throw "Index out of bounds" ;
        }
        node* curr=head;

        for(int j = 0; j<index;j++){
            curr=curr->next;
        }

        curr->next->prev=curr->prev;

        if(index==0){
            head=curr->next;
        }else{
            curr->prev->next=curr->next;
        }

        length--;
        delete curr;

    }

    /**
     * removes the first element that matches o if it exists
     * @param o
     *
     */
    void remove(const T& o){

        node* curr=head;

        while((curr->elem!=o&&curr!=tail)){
            curr=curr->next;
        }
        if(curr!=tail){
            if(curr==head){
                if(head->next!=tail){
                    head=head->next;
                }else{
                    head= nullptr;
                }
            }else{
                curr->prev->next=curr->next;
            }
            length--;
            delete curr;

        }

    }

    /**
    * returns an ConstIterator pointing on the head of the list
    * @return  ConstIterator pointing on the head
    */
    ConstIterator begin()const{
        return ConstIterator(head);
    }

    /**
    * returns an Iterator pointing on the head of the list
    * @return  Iterator pointing on the head
    */
    Iterator begin(){
        return Iterator(head);
    }


    /**
    * return an ConstIterator pointing on the tail of the list
    * @return  ConstIterator pointing on the tail
    */
    ConstIterator end()const {
        if(empty())
            return begin();

        return ConstIterator(tail);
    }

    /**
     * return an Iterator pointing on the tail of the list
     * @return  Iterator pointing on the tail  
     */
    Iterator end() {
        if(empty())
            return begin();

        return Iterator(tail);
    }



    /**
     * returns the size of the list
     * @return the size of the list
     */
    size_t size()const{

        return length;
    }

    /**
     * Method used to add an element at the start of the list
     * @param o the object that we want to add
     */
    void insert(const T& o){

        if(empty()){
            head= new node(o, nullptr, tail);
        }else{
            head= new node(o, nullptr, head);
        }

        if(head->next!= nullptr){
            head->next->prev=head;
        }

        length++;
    }

    /**

     * Method used to add an element at the end of the list
     * @param o the object that we want to add

     */
    void append(const T& o){
        if(empty()){
            head= new node(o, nullptr, tail);

            tail->prev=head;
        }else{
            tail->prev=new node(o, tail->prev, tail);
            tail->prev->prev->next=tail->prev;
        }

        length++;
    }

    /**
     * Method used to find an object in the list and return the
     * index of the first element we find.
     * @param o the object we want to find
     * @return the index of the first element corresponding, -1 otherwise.
     */
    int find(const T& o){
        int count = 0;
        for (List<T>::Iterator it = this->begin(); it != this->end(); ++it){
            if(o == *it){
                return count;
            }
            count++;
        }
        return -1;
    }




};

#endif //LABO3CPP_LIST_H
