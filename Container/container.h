#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
namespace container {
/**
 *
 */
template<class T>class Container
{
private:
    /**
     * @brief The Node class
     */
    class Node{
    public:
        const T* data;
        Node* previous;
        Node* next;
        /**
         * @brief Node
         * @param fData
         * @param fPrevious
         * @param fNext
         */
        Node(const T* fData,Node* fPrevious=nullptr,Node* fNext=nullptr){
            data = *fData;
            previous = fPrevious;
            next = fNext;
        }
        /**
         * @brief Node
         * @param fData
         * @param fPrevious
         * @param fNext
         */
        Node(const T& fData,Node* fPrevious=nullptr,Node* fNext=nullptr){
            data = &fData;
            previous = fPrevious;
            next = fNext;
        }

        Node(const Node& c){
            this->data = c.data;
            this->previous = c.previous;
            this->next = c.next;
        }
        void setNext(Node* next){
            this->next = next;
        }

        void setPrevious(Node* previous){
            this->previous = previous;
        }

        void setData(const T* data){
            this->data = data;
        }

        Node(){
            data = nullptr;
            previous = this;
            next = this;
        }
        ~Node(){
            if(data)
                delete data;
        }
    };

    Node* handle;
    int size;
public:
    Container(){
        handle = new Node();
        size = 0;
    }
    /**
     * @brief push_front
     * @param value
     */

    void push_front(const T* value){
        Node* next = handle;
        if(size>0)//check if is the first element to be inserted
            next = handle->next;
        Node* l_nodo = new Node(value,handle,next);
        if(next != handle)
            next->setPrevious(l_nodo);
        else
            handle->setPrevious(l_nodo);
        handle->next = l_nodo;
        size++;
    }

    /**
     * @brief push_back
     * @param value
     */
    void push_back(const T* value){
        Node* previous = handle;
        if(size>0) //check if is the first element to be inserted
            previous = handle->previous;
        Node* l_nodo = new Node(value,previous,handle);
        if(previous != handle) // mantain the coherence in the data structure
            previous->setNext(l_nodo);
        else
            handle->setNext(l_nodo);
        handle->previous = l_nodo;
        size++;
    }
};

}
#endif // CONTAINER_H
