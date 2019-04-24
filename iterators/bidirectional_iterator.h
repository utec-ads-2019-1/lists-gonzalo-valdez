#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
<<<<<<< HEAD
            this->current=other.current;
            return (*this);
=======
            return other;
>>>>>>> refs/remotes/origin/master
        }

        bool operator!=(BidirectionalIterator<T> other) {
            if (this->current != other.current) {
                return true;
            }
            return false;
        }

        BidirectionalIterator<T> operator++() {
            return BidirectionalIterator<T>(this->current->next);
        }

        BidirectionalIterator<T> operator--() {
            return BidirectionalIterator<T>(this->current->prev);
        }

        T operator*() {
            return this->current->data;
        }
};

#endif