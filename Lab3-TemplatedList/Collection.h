// Nicholas Miller

#include "list.h"
#include <iostream>
#ifndef COLLECTION_H
#define COLLECTION_H

template<typename T>
class Collection {
public:
    Collection(): front_(nullptr) {}
    void addItem(const T&);
    void removeItem(const T&);
    T lastItem() const {return front_->getData();}
    void printCollection();

private:
    node<T> *front_;
};

template<typename T>
void Collection<T>::addItem(const T &item) {
    node<T> *newNode = new node<T>;
    newNode->setData(item);
    newNode->setNext(front_);
    front_ = newNode;
}

template<typename T>
void Collection<T>::removeItem(const T &item) {
    while (front_ != nullptr && front_->getData() == item) {
        node<T> *tmp = front_;
        tmp = front_->getNext();
        delete front_;
        front_ = tmp;
    }

    node<T> *temp = front_;
    node<T> *temp2 = temp->getNext();

    while (temp2 != nullptr) {
        if (temp2->getData() == item) {
            temp->setNext(temp2->getNext());
            delete temp2;
            temp2 = temp->getNext();
        }
        else {
            temp = temp->getNext();
            temp2 = temp2->getNext();
        }
    }
}

template<typename T>
void Collection<T>::printCollection() {
    node<T> *temp = front_;
    while (temp != nullptr) {
        std::cout << temp->getData() << " ";
        temp = temp->getNext();
    }
}

#endif // COLLECTION_H