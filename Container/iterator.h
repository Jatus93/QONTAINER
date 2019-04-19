#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"
template<class T> class Iterator{
private:
    friend class Container<T>;
    mutable Node<T>* current;
    const Container<T>* container;
    /**
     * @brief Iterator
     * @param eContainer
     * @param startNode
     */
    Iterator(const Container<T>* eContainer, Node<T>* startNode = nullptr):container(eContainer){
        if(!startNode)
            current = container->handle->next;
        else
            current = startNode;
    }

    void invalidIterator() const{
        if(!container && !current)
            throw std::bad_function_call();
    }
public:
    /**
     * @brief Iterator
     */

    Iterator():container(nullptr),current(nullptr){}

    /**
     * @brief Iterator
     * @param e
     */
    Iterator(const Iterator& e):Iterator(e.container,e.current){}
    Iterator(const Iterator* e):Iterator(e->container,e->current){}


    /**
     * @brief operator --
     */
    void operator--(int) const{
        invalidIterator();
        if(current){
            if(!current->previous->first)
                current = current->previous;
            else
                current = nullptr;
        }else {
            current = container->handle->previous;
        }
    }
    /**
     * @brief operator ++
     */
    void operator++(int) const{
        invalidIterator();
        if(current){
            if(!current->next->first)
                current = current->next;
            else
                current = nullptr;
        }else{
            current = container->handle->next;
        }
    }

    /**
     * @brief operator *
     * @return
     */
    const T& operator*() const{
        invalidIterator();
        return (current->data);
    }
    /**
     * @brief getData
     * @return
     */
    const T& getData() const{
        invalidIterator();
        return (current->data);
    }

    /**
     * @brief operator =
     * @param data
     */
    void operator=(const T* data){
        invalidIterator();
        if(current){
            Node<T>* temp = new Node<T>(*data,current->next,current->previous);
            current->previous->next = temp;
            current->next->previous = temp;
            delete current;
            current = temp;
        }
    }
    /**
     * @brief operator ==
     * @param it
     * @return
     */
    bool operator==(const Iterator& it) const{
        invalidIterator();
        return ((container==it.container) && (current == it.current));
    }
    /**
     * @brief operator ==
     * @param v
     * @return
     */
    bool operator==(const T* v) const{
        invalidIterator();
        if((current == nullptr) && (v == nullptr))
            return true;
        return (&current->data == v);
    }
    /**
     * @brief operator !=
     * @param v
     * @return
     */
    bool operator!=(const T* v) const{
        return !(*this == v);
    }

};
#endif // ITERATOR_H
