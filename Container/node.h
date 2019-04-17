#ifndef NODE_H
#define NODE_H


template<class T> class Node{
private:
    friend class Container<T>;
    friend class Iterator<T>;
    const bool first;
    const T& data;
    Node<T>* previous;
    Node<T>* next;
    /**
 * @brief Node
 * @param fData
 * @param fPrevious
 * @param fNext
 */
    Node(const T& fData,Node<T>* fPrevious=nullptr,Node<T>* fNext=nullptr):data(fData),first(false){
        previous = fPrevious;
        next = fNext;
    }

    /**
 * @brief Node
 * @param c
 */
    Node(const Node& c):data(c.data),first(c.first){
        this->previous = c.previous;
        this->next = c.next;
    }
    Node():data(data),first(true){
        previous = this;
        next = this;
    }
    ~Node(){
        if(next != this && previous!=this){
            previous->next = next;
            next->previous = previous;
        }
        previous=nullptr;
        next = nullptr;
    }
};

#endif // NODE_H
