#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"
template<class T> class Iterator{
private:
    friend class Container<T>;
    Node<T>* current;
    Container<T>* container;
    /**
     * @brief Iterator
     * @param eContainer
     * @param startNode
     */
    Iterator(Container<T>* eContainer, Node<T>* startNode = nullptr):container(eContainer){
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
    Iterator():container(nullptr),current(nullptr){}
    /**
     * @brief Iterator
     * @param e
     */
    Iterator(const Iterator& e):Iterator(e.handle,e.current){}

    /**
     * @brief operator --
     */
    void operator--(int){
        invalidIterator();
        if(current){
            if(current->previous != container->handle)
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
    void operator++(int){
        invalidIterator();
        if(current){
            if(current->next != container->handle)
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
     * @brief insertAfter
     * @param data
     */
    void insertAfter(const T& data){
        invalidIterator();
        container->insert(current,data);
    }
    /**
     * @brief insertBefore
     * @param data
     */
    void insertBefore(const T& data){
        invalidIterator();
        container->insert(current->previous,data);
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

};
#endif // ITERATOR_H
