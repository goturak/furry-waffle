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
    node* head;
    node* tail;

public:
    List() : head(nullptr ), tail (nullptr ) {}


  //  List(const List& l):head(nullptr), tail(nullptr){


    //}

private:
    class GenericIterator{
    protected:
        node* value;
    public:
        T& operator++(){
            value = value->next;
            return value->elem;
        }

        T& operator--(){
            value = value->prev;
            return value->elem;
        }

        T* operator->(){
            return value->elem;
        }

        bool operator==(GenericIterator& it){
            return *value->elem==*it.value->elem;
        }

        bool operator!=(GenericIterator it){
            return value->elem!=it.value->elem;
        }
    };

public:
    class Iterator : public GenericIterator{
    public:
        Iterator(node* n){
            GenericIterator::value = n;
        }


        T& operator*(){
            return GenericIterator::value->elem;
        }
    };

    class ConstIterator :public  GenericIterator{
    public:
        ConstIterator(node* n){
            GenericIterator::value = n;
        }

        const T& operator*(){
            const T& v = GenericIterator::value->elem;
            return v;
        }

    };

    /**
     * constructeur avec initializer list
     * @param args initializer list
     */
    List(std::initializer_list<T> args)
            : head(nullptr), tail(nullptr) {
        int i = 0;
        for (const T *val = args.begin(); val != args.end(); ++val)
            append(*val);

    }


    T operator[](int i) {
        if(i>size()){
            cout << "Index out of bounds" <<endl;
        }
    }

    /**
     * overloads assignement operator (=)
     * @param t
     */
    void operator=(List<T> t){
        head=t.head;
        tail=t.tail;
    }

    ostream& operator<<(ostream& os)
    {
       // os << dt.mo << '/' << dt.da << '/' << dt.yr;
        return os;
    }

    /**
     *
     * @return if the list is empty or not
     */
    bool empty() const { return ( !head ||!tail ); }


    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(tail);
    }

    /**
     * returns the size of the list
     * @return the size of the list
     */
    int size(){
        if(empty())
            return 0;

        node* curr= head;
        int count= 1;

        while(curr!=tail){
            curr=curr->next;
            count++;
        }

        return count;
    }

    /**
     * inserts the element o at the begining of the list
     * @param o the element to insert
     */
    void insert(const T& o){
        head= new node(o, nullptr, head);
        if(empty()){
            tail=head;
        }

        if(head->next!= nullptr){
            head->next->prev=head;
        }

    }

    void append(const T& o){
        tail= new node(o, tail, nullptr);
        if(empty()){
            head=tail;
        }

        if(tail->prev!= nullptr){
            tail->prev->next=tail;
        }

    }

};

#endif //LABO3CPP_LIST_H
