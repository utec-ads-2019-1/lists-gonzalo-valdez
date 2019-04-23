#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
            return other;
        }

        bool operator!=(ForwardIterator<T> other) {
            if (this->current != other.current) {
                return true;
            }
            return false;
        }

        ForwardIterator<T> operator++() {
            return ForwardIterator<T>(this->current->next);
        }

        T operator*() {
            return this->current->data;
        }
};

#endif