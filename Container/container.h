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
    Node<T>* getElement(const int& i) const{
        if(i>(cSize/2))
            return getElementFromEnd(i);
        return getElementFromStart(i);
    }
    /**
     * @brief getElementFromTop
     * @param i
     * @return
     */
    Node<T>* getElementFromEnd(const int& i) const{
        int index = cSize;
        Node<T>* pointer = handle->previous->next;
        while(index>i){
            index--;
            pointer = pointer->previous;
        }
        return pointer;
    }
    /**
     * @brief getElementFromBottom
     * @param i
     * @return
     */
    Node<T>* getElementFromStart(const int& i) const{
        int index = 0;
        Node<T>* pointer = handle->next;
        while (index<i) {
            index++;
            pointer = pointer->next;
        }
        return pointer;
    }

    void insert(Node<T>* node, const T& value){
        Node<T>* newNode = new Node<T>(value,node,node->next);
        if (newNode == nullptr)
            throw std::bad_alloc();
        node->next->previous = newNode;
        node->next = newNode;
        cSize++;
    }

    const Node<T>* handle;
    int cSize;
public:
    /**
     * @brief Container
     */
    Container():handle(new Node<T>()){
        cSize = 0;
    }
    /**
     * @brief Container
     * @param c
     */
    Container(const Container<T>& c):handle(c.handle){
        cSize = c.cSize;
    }
    /**
     * @brief Container
     * @param c
     */
    Container(const Container<T>* c):handle(c->handle){
        cSize = c->size();
    }

    /**
     * @brief clone
     * @return
     */

    Container<T>* clone() const{
        Container<T>* temp = new Container<T>();
        for(int i=0; i<cSize; i++)
            temp->pushBack(*(new T((*this)[i])));
        return temp;
    }

    /**
     * @brief push_front
     * @param value
     */

    void pushFront(const T& value){
        insert(0,value);
    }

    /**
     * @brief push_back
     * @param value
     */
    void pushBack(const T& value){
        insert(cSize,value);
    }

    /**
     * @brief insert
     * @param i
     * @param value
     */
    void insert(const int i, const T& value){
        Node<T>* element = getElement(i)->previous;
        insert(element,value);
    }

    /**
     * @brief insertAfterIterator
     * @param it
     */
    void insertAfterIterator(const Iterator<T>& it, const T& value){
        insert(it.current,value);
    }


    /**
     * @brief operator []
     * @param index
     * @return
     */
    const T& operator[](int index) const{
        if(index >= cSize || index <0)
            throw std::out_of_range("Index is out of range");
        return getElement(index)->data;
    }
    /**
     * @brief deleteElementAt
     * @param i
     */
    void deleteElementAt(int i){
        if(i >= cSize || i <0)
            throw std::out_of_range("Index is out of range");
        delete getElement(i);
        cSize--;
    }
    /**
     * @brief getIterator
     * @return
     */
    Iterator<T>* getIterator(){
        return getIteratorAt(0);
    }

    /**
     * @brief getConstInterator
     * @return const Iterator
     */

    const Iterator<T>* getConstIterator() const{
        return getConstIteratorAt(0);
    }

    /**
     * @brief getConstInteratorAt
     * @param index
     * @return const Iterator
     */
    const Iterator<T>* getConstIteratorAt(int index) const{
        if(cSize == 0)
            throw std::logic_error("Empty contanier cannot build an iterator");
        return new Iterator<T>(this,getElement(index));
    }
    /**
     * @brief getIteratorAt
     * @param index
     * @return
     */
    Iterator<T>* getIteratorAt(int index){
        if(cSize == 0)
            throw std::logic_error("Empty contanier cannot build an iterator");
        return new Iterator<T>(this,getElement(index));
    }
    /**
     * @brief size
     * @return
     */
    int size() const noexcept{
        return cSize;
    }
    ~Container(){
        while(cSize>0){
            deleteElementAt(cSize-1);
        }
    }
};
#endif // CONTAINER_H
#include "iterator.h"
