#ifndef NODE_H
#define NODE_H


template<class T> class Node{
private:
    friend class Container<T>;
    friend class Iterator<T>;
    const bool first;
    T data;
    Node<T>* previous;
    Node<T>* next;
    /**
 * @brief Node
 * @param fData
 * @param fPrevious
 * @param fNext
 */
    Node(const T& fData,Node<T>* fPrevious=nullptr,Node<T>* fNext=nullptr):first(false){
        data = fData;
        previous = fPrevious;
        next = fNext;
    }

    /**
 * @brief Node
 * @param c
 */
    Node(const Node& c):first(c.first){
        data = c.data;
        this->previous = c.previous;
        this->next = c.next;
    }
    Node():first(true){
        previous = this;
        next = this;
    }
    ~Node(){
        if(!this->first){
            previous=this;
            next = this;
        }
    }
};

#endif // NODE_H
