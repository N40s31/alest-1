#include "IntDoubleLinkedDeque.hpp"
#include <sstream>

IntDoubleLinkedDeque::IntDoubleLinkedDeque() {front = nullptr, back = nullptr, numElements = 0;}
IntDoubleLinkedDeque::~IntDoubleLinkedDeque(){
    clear();
}

int IntDoubleLinkedDeque::size() const{
    return numElements;
}

bool IntDoubleLinkedDeque::isEmpty() const{
    return numElements == 0;
}

void IntDoubleLinkedDeque::addFirst(const int e){
    Node *aux = new Node(e);

    if(isEmpty()){front = aux; back = aux;}
    else{
    aux->next = front;
    front->prev = aux;
    front = aux;
    }
    
    numElements++;
}

void IntDoubleLinkedDeque::addLast(const int e){
    Node *aux = new Node(e);

    if(isEmpty()){ front = back = aux;}

    else{
        
        aux->prev = back;
        back->next = aux;
        back = aux;
    }
    numElements++;
}

bool IntDoubleLinkedDeque::removeFirst(int &e){
    if(isEmpty()) return false;
    else{
        
        Node *aux = front;
        e = front->data;
        front = front->next;
        delete aux;

        if(front == nullptr) back = nullptr;
            else front->prev = nullptr;

        numElements--;
        return true;
    }
}

bool IntDoubleLinkedDeque::removeLast(int &e){
    if(isEmpty()) return false;
    else{
        
        Node *aux = back;
        e = back->data;
        back = back->prev;
        delete aux;

        if(back == nullptr) front = nullptr;
        else back->next = nullptr;

        numElements--;
        return true;
    }
}

bool IntDoubleLinkedDeque::first(int &e) const{
    if(isEmpty()) return false;
    else {
        e = front->data;
        return true;  
    } 
}

bool IntDoubleLinkedDeque::last(int &e) const{
    if(isEmpty())return false;
    else {
        e = back->data;
        return true;
    }
}

void IntDoubleLinkedDeque::clear(){
    while(front != nullptr){
        if(numElements == 0) front = back = nullptr;
        Node *aux = front;
        front = front->next;
        delete aux;  
    }
    numElements = 0;
    back = nullptr;
}

string IntDoubleLinkedDeque :: str () const {
stringstream ss ;
ss << "|";
for ( Node * aux = front ; aux != nullptr ; aux = aux -> next )
ss << aux -> data << "|";
return ss . str ();
}
string IntDoubleLinkedDeque :: reverseStr () const {
stringstream ss ;
ss << "|";
for ( Node * aux = back ; aux != nullptr ; aux = aux -> prev )
ss << aux -> data << "|";
return ss . str ();
}