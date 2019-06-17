#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <signal.h>
#include <typeinfo>
template<class T> class Iterator;
template<class T> class Node;
template<class T> class Container{
private:
    friend class Iterator<T>;
    /**
     * @brief getElement
     * @param i
     * @return
     */
    Node<T>* getElement(const int& i) const;
    /**
     * @brief getElementFromTop
     * @param i
     * @return
     */
    Node<T>* getElementFromEnd(const int& i) const;
    /**
     * @brief getElementFromBottom
     * @param i
     * @return
     */
    Node<T>* getElementFromStart(const int& i) const;
    /**
     * @brief insert
     * @param node
     * @param value
     */
    void insert(Node<T>* node, const T& value);

    /**
     * @brief deleteNode
     * @param toDelete
     */
    void deleteNode(Node<T>* toDelete);

    const Node<T>* handle;
    int cSize;
public:
    /**
     * @brief Container
     */
    Container();
    /**
     * @brief Container
     * @param c
     */
    Container(const Container<T>& c);
    /**
     * @brief Container
     * @param c
     */
    Container(const Container<T>* c);

    /**
     * @brief clone
     * @return
     */
    Container<T>* clone() const;

    /**
     * @brief push_front
     * @param value
     */

    void pushFront(const T& value);

    /**
     * @brief push_back
     * @param value
     */
    void pushBack(const T& value);
    /**
     * @brief search
     * @param value
     * @return
     */
    const Iterator<T>& search(const T& value) const;

    /**
     * @brief insert
     * @param i
     * @param value
     */
    void insert(const int i, const T& value);

    /**
     * @brief insertAfterIterator
     * @param it
     */
    void insertAfterIterator(const Iterator<T>& it, const T& value);

    /**
     * @brief operator []
     * @param index
     * @return
     */
    const T& operator[](int index) const;
    /**
     * @brief deleteElementAt
     * @param i
     */
    void deleteElementAt(int i);

    /**
     * @brief deleteElementAt
     * @param it
     */
    void deleteElementAt(const Iterator<T>& it);
    /**
     * @brief getIterator
     * @return
     */
    Iterator<T>* getIterator();
    /**
     * @brief getConstInterator
     * @return const Iterator
     */

    const Iterator<T>* getConstIterator() const;

    /**
     * @brief getConstInteratorAt
     * @param index
     * @return const Iterator
     */
    const Iterator<T>* getConstIteratorAt(int index =0) const;

    /**
     * @brief getIteratorAt
     * @param index
     * @return
     */
    Iterator<T>* getIteratorAt(int index = 0);
    /**
     * @brief size
     * @return
     */
    int size() const noexcept;

    ~Container();
};

// PUBLIC METHODS
template <class T> Container<T>::Container():handle(new Node<T>()){
    cSize = 0;
}

template <class T> Container<T>::Container(const Container<T>& c):handle(c.handle){
    cSize = c.cSize;
}

template <class T> Container<T>::Container(const Container<T>* c):handle(c->handle){
    cSize = c->size();
}

template <class T> Container<T>* Container<T>::clone() const{
    Container<T>* temp = new Container<T>();
    Iterator<T> it = getConstIterator();
    while(it!=nullptr){
        temp->pushBack(*(new T(*it)));
        it++;
    }
    return temp;
}

template <class T> void Container<T>::pushFront(const T& value){
    insert(0,value);
}

template <class T> void Container<T>::pushBack(const T& value){
    insert(cSize,value);
}

template <class T> const Iterator<T>& Container<T>::search(const T& value) const{
    const Iterator<T> it(getConstIterator());
    while(it!=nullptr && it.getData()!=value)
        it++;
    return *(new Iterator<T>(it));
}

template <class T> void Container<T>::insert(const int i, const T& value){
    Node<T>* element = getElement(i)->previous;
    insert(element,value);
}

template <class T> void Container<T>::insertAfterIterator(const Iterator<T>& it, const T& value){
    insert(it.current,value);
}

template <class T> const T& Container<T>::operator[](int index) const{
    if(index >= cSize || index <0)
        throw std::out_of_range("Index is out of range");
    return getElement(index)->data;
}

template <class T> void Container<T>::deleteElementAt(int i){
    if(i >= cSize || i <0)
        throw std::out_of_range("Index is out of range");
    deleteNode(getElement(i));
}

template <class T> void Container<T>::deleteElementAt(const Iterator<T>& it){
    if(it==nullptr)
        throw std::logic_error("Iterator past end");
    Node<T>* n = it.current;
    it++;
    deleteNode(n);
}

template <class T> Iterator<T>* Container<T>::getIterator(){
    return getIteratorAt();
}

template <class T> const Iterator<T>* Container<T>::getConstIterator() const{
    return getConstIteratorAt();
}

template <class T> const Iterator<T>* Container<T>::getConstIteratorAt(int index) const{
    if(cSize == 0 || index < 0 || index >= cSize)
        return new Iterator<T>(this);
    return new Iterator<T>(this,getElement(index));
}

template <class T> Iterator<T>* Container<T>::getIteratorAt(int index){
    if(cSize == 0 || index < 0 || index >= cSize)
        return new Iterator<T>(this);
    return new Iterator<T>(this,getElement(index));
}

template<class T> int Container<T>::size() const noexcept{
    return cSize;
}

template <class T> Container<T>::~Container(){
    while(cSize>0){
        deleteElementAt(cSize-1);
    }
}

//PRIVATE METHODS

template <class T> Node<T>* Container<T>::getElement(const int& i) const{
    if(i>((cSize/2)))
        return getElementFromEnd(i);
    return getElementFromStart(i);
}

template <class T> Node<T>* Container<T>::getElementFromEnd(const int& i) const{
    int index = cSize-1;
    Node<T>* pointer = handle->previous->next;
    while(index>=i){
        index--;
        pointer = pointer->previous;
    }
    return pointer;
}

template <class T> Node<T>* Container<T>::getElementFromStart(const int& i) const{
    int index = 0;
    Node<T>* pointer = handle->next;
    while (index<i) {
        index++;
        pointer = pointer->next;
    }
    return pointer;
}

template <class T> void Container<T>::insert(Node<T>* node, const T& value){
    Node<T>* newNode = new Node<T>(value,node,node->next);
    if (newNode == nullptr)
        throw std::bad_alloc();
    node->next->previous = newNode;
    node->next = newNode;
    cSize++;
}

template <class T> void Container<T>::deleteNode(Node<T>* toDelete){
    toDelete->previous->next = toDelete->next;
    toDelete->next->previous = toDelete->previous;
    delete toDelete;
    cSize--;
}

#endif // CONTAINER_H
#include "iterator.h"
