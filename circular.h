#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
            Node<T> *newnode = new Node<T>(value);
            if (this->size() == 1) {
                newnode->next = this->head;
                newnode->prev= this->head;
                this->head->prev = newnode;
                this->head->next = newnode;
                this->head = newnode;

            }
            if (this->size()>1) {
                newnode->next = this->head;
                newnode->prev= this->tail;
                this->head->prev = newnode;
                this->head = newnode;

                this->tail->next=this->head;
            } else {
                this->head=this->tail=newnode;
            }
        }

        void push_back(T value) {
            Node<T>* newnode = new Node<T>(value);
            if (this->size() == 1) {
                this->tail->next = newnode;
                newnode->prev = this->tail;
                this->tail = newnode;

            } if (this->size()>1) {
                this->tail->next = newnode;
                newnode->prev = this->tail;
                this->tail = newnode;
                this->head->prev=this->tail;
            } else {
                this->head=this->tail=newnode;
            }
        }

        void pop_front() {
            Node<T>* temp = this->head;
            this->head = this->head->next;
            this->head->prev=this->tail;
            this->tail->next=this->head;
            delete temp;
        }

        void pop_back() {
            Node<T>* temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next=this->head;
            this->head->prev=this->tail;
            delete temp;
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
            while(n->next!=this->head){
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

        void sort() {
            vector<T> temp;
            temp.resize(this->size());
            for(int i = 0;i<this->size();i++){
                temp.push_back((*this)[i]);
            }
            this->clear();
            std::sort(temp.begin(),temp.end());
            for(int i = 0;i<this->size();i++){
                this->push_back(temp.at(i));
            }
        }
    
        void reverse() {
            vector<T> temp;
            temp.resize(this->size());
            for(int i = 0;i<this->size();i++){
                temp.push_back((*this)[i]);
            }
            this->clear();
            std::reverse(temp.begin(),temp.end());
            for(int i = 0;i<this->size();i++){
                this->push_back(temp.at(i));
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->tail);
        }

        void merge(CircularLinkedList<T> list) {
            for(auto k:list){
                this->push_back(k);
            }
        }
};

#endif