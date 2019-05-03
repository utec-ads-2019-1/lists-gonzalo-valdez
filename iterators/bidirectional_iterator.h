#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current=other.current;
            return (*this);
        }

        bool operator!=(BidirectionalIterator<T> other) {
            if (this->current != other.current) {
                return true;
            }
            return false;
        }

        BidirectionalIterator<T> operator++() {
            // Estás creando nuevos iteradores cada vez
            return BidirectionalIterator<T>(this->current->next);
        }

        BidirectionalIterator<T> operator--() {
            // Estás creando nuevos iteradores cada vez
            return BidirectionalIterator<T>(this->current->prev);
        }

        T operator*() {
            // Si es una lista vacía?
            return this->current->data;
        }
};

#endif