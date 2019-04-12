#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include <math.h>

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if (this->head!=nullptr) {
                return this->head->data;
            } else {
                throw out_of_range("List empty, no front exists.");
            }
        }

        T back() {
            if (this->tail!=nullptr) {
                return this->tail->data;
            } else {
                throw out_of_range("List empty, no tail exists.");
            }
        }

        void push_front(T value) {
            Node<T>* newnode = new Node<T>(value);
            if (this->head) {
                newnode->next=this->head;
                this->head=newnode;

            } else {
                this->head=this->tail=newnode;
            }
        }

        void push_back(T value) {
            Node<T>* newnode = new Node<T>(value);
            if (this->tail) {
                this->tail->next=newnode;
                this->tail=newnode;

            } else {
                this->head=this->tail=newnode;
            }
        }

        void pop_front() {
            Node<T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }

        void pop_back() {
            Node<T>* n = this->head;
            while(n->next != this->tail) {
                n=n->next;
            }
            n->next=nullptr;
            delete this->tail;
            this->tail=n;
        }

        T operator[](int index) {
            if (index>this->size()) {
                throw out_of_range("Index out of range");
            }
            Node<T>* n = this->head;
            for(int i=0;i<index;i++){
                n=n->next;
            }
            return n->data;
        }

        bool empty() {
            if(this->head){
                return false;
            } else{
                return true;
            }
        }

        int size() {
            Node<T>* n = this->head;
            int count = 0;
            while(n->next){
                count++;
                n=n->next;
            }
            return count;
        }

        void clear() {
            if(not this->empty()) {
                for(int i=0;i<this->size();i++){
                    Node<T>* n = this->head->next;
                    delete this->head;
                    this->head=n;
                }
            }
        }


        Node<T> getNode(int index) {
            if (index>this->size()) {
                throw out_of_range("Index out of range");
            }
            Node<T>* n = this->head;
            for(int i=0;i<index;i++){
                n=n->next;
            }
            return n;
        }

        void sort() {
            for(int i = 0;i<this->size();i++){
                for(int j = 0;j<this->size();j++){
                    if((*this)[i] > (*this)[j]){

                    }
                }
            }
        }
    
        void reverse() {
            int count = 0;
            for(int i = 0; i<floor(size()/2); i++){
                (*this)[i].data = (*this)[i-count].data;
                count++;
            }
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

	    ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            // TODO
        }
};

#endif