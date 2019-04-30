//
// Created by goturak on 30/04/19.
//

#ifndef LABO3CPP_LIST_H
#define LABO3CPP_LIST_H

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

    bool empty() const { return ( !head ||!tail ); }

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
