#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value){
        data = value;
        next=prev=nullptr;
    }
    void killSelf() {
        // TODO
    }
};

#endif