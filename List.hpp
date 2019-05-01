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

    node nullNode= node(0, nullptr, nullptr);
    node* head;
    node* tail;



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






public:
    List() : head(nullptr ), tail (&nullNode ) {}


  //  List(const List& l):head(nullptr), tail(nullptr){


    //}


    /**
     * constructeur avec initializer list
     * @param args initializer list
     */
    List(std::initializer_list<T> args)
            : head(nullptr), tail(&nullNode) {
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
    bool empty() const { return ( !head ); }


    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        if(empty())
            return begin();

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
        int count= 0;

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

        if(empty()){
            head= new node(o, nullptr, tail);
        }else{
            head= new node(o, nullptr, head);
        }

        if(head->next!= nullptr){
            head->next->prev=head;
        }

    }

    void append(const T& o){

        if(empty()){
            head= new node(o, nullptr, tail);

            tail->prev=head;
        }else{
            tail->prev=new node(o, tail->prev, tail);
            tail->prev->prev->next=tail->prev;
        }



    }



};

#endif //LABO3CPP_LIST_H
