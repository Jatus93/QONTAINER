#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <signal.h>
#include <typeinfo>
template<class T> class Container{
private:
    friend class Iterator;
    class Node{
    public:
        friend class Iterator;
        const bool first;
        T data;
        Node* previous;
        Node* next;
        /**
     * @brief Node
     * @param fData
     * @param fPrevious
     * @param fNext
     */
        Node(const T& fData,Node* fPrevious=nullptr,Node* fNext=nullptr):first(false){
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
    /**
     * @brief getElement
     * @param i
     * @return
     */
    Node* getElement(const int& i) const;
    /**
     * @brief getElementFromTop
     * @param i
     * @return
     */
    Node* getElementFromEnd(const int& i) const;
    /**
     * @brief getElementFromBottom
     * @param i
     * @return
     */
    Node* getElementFromStart(const int& i) const;
    /**
     * @brief insert
     * @param node
     * @param value
     */
    void insert(Node* node, const T& value);

    /**
     * @brief deleteNode
     * @param toDelete
     */
    void deleteNode(Node* toDelete);

    const Node* handle;
    int cSize;
public:
    class Iterator{
    private:
        friend class Container<T>;
        mutable Node* current;
        const Container<T>* container;
        /**
         * @brief Iterator
         * @param eContainer
         * @param startNode
         */
        Iterator(const Container<T>* eContainer, Node* startNode = nullptr);

        void invalidIterator() const;
    public:
        /**
         * @brief Iterator
         */

        Iterator();

        /**
         * @brief Iterator
         * @param e
         */
        Iterator(const Iterator& e);
        Iterator(const Iterator* e);


        /**
         * @brief operator --
         */
        void operator--(int) const;
        /**
         * @brief operator ++
         */
        void operator++(int) const;

        /**
         * @brief operator *
         * @return
         */
        const T& operator*() const;
        /**
         * @brief getData
         * @return
         */
        const T& getData() const;

        /**
         * @brief operator =
         * @param data
         */
        void operator=(const T* data);
        /**
         * @brief operator ==
         * @param it
         * @return
         */
        bool operator==(const Iterator& it) const;
        /**
         * @brief operator ==
         * @param v
         * @return
         */
        bool operator==(const T* v) const;
        /**
         * @brief operator !=
         * @param v
         * @return
         */
        bool operator!=(const T* v) const;
    };
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
    const Iterator& search(const T& value) const;

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
    void insertAfterIterator(const Iterator& it, const T& value);

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
    void deleteElementAt(const Iterator& it);
    /**
     * @brief getIterator
     * @return
     */
    Iterator* getIterator();
    /**
     * @brief getConstInterator
     * @return const Iterator
     */

    const Iterator* getConstIterator() const;

    /**
     * @brief getConstInteratorAt
     * @param index
     * @return const Iterator
     */
    const Iterator* getConstIteratorAt(int index =0) const;

    /**
     * @brief getIteratorAt
     * @param index
     * @return
     */
    Iterator* getIteratorAt(int index = 0);
    /**
     * @brief size
     * @return
     */
    int size() const noexcept;

    ~Container();
};
/***
 * CONTAINER DEFINITION *
 * */
// PUBLIC METHODS

template <class T> Container<T>::Container():handle(new Container<T>::Node()){
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
    Iterator it = getConstIterator();
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

template <class T> const typename Container<T>::Iterator& Container<T>::search(const T& value) const{
    const Iterator it(getConstIterator());
    while(it!=nullptr && it.getData()!=value)
        it++;
    return *(new Iterator(it));
}

template <class T> void Container<T>::insert(const int i, const T& value){
    Node* element = getElement(i)->previous;
    insert(element,value);
}

template <class T> void Container<T>::insertAfterIterator(const Iterator& it, const T& value){
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

template <class T> void Container<T>::deleteElementAt(const Iterator& it){
    if(it==nullptr)
        throw std::logic_error("Iterator past end");
    Node* n = it.current;
    it++;
    deleteNode(n);
}

template <class T> typename Container<T>::Iterator* Container<T>::getIterator(){
    return getIteratorAt();
}

template <class T> const typename Container<T>::Iterator* Container<T>::getConstIterator() const{
    return getConstIteratorAt();
}

template <class T> const typename Container<T>::Iterator* Container<T>::getConstIteratorAt(int index) const{
    if(cSize == 0 || index < 0 || index >= cSize)
        return new Iterator(this);
    return new Iterator(this,getElement(index));
}

template <class T> typename Container<T>::Iterator* Container<T>::getIteratorAt(int index){
    if(cSize == 0 || index < 0 || index >= cSize)
        return new Iterator(this);
    return new Iterator(this,getElement(index));
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

template <class T> typename Container<T>::Node* Container<T>::getElement(const int& i) const{
    if(i>((cSize/2)))
        return getElementFromEnd(i);
    return getElementFromStart(i);
}

template <class T> typename Container<T>::Node* Container<T>::getElementFromEnd(const int& i) const{
    int index = cSize-1;
    Node* pointer = handle->previous->next;
    while(index>=i){
        index--;
        pointer = pointer->previous;
    }
    return pointer;
}

template <class T> typename Container<T>::Node* Container<T>::getElementFromStart(const int& i) const{
    int index = 0;
    Node* pointer = handle->next;
    while (index<i) {
        index++;
        pointer = pointer->next;
    }
    return pointer;
}

template <class T> void Container<T>::insert(Node* node, const T& value){
    Node* newNode = new Node(value,node,node->next);
    if (newNode == nullptr)
        throw std::bad_alloc();
    node->next->previous = newNode;
    node->next = newNode;
    cSize++;
}

template <class T> void Container<T>::deleteNode(Node* toDelete){
    toDelete->previous->next = toDelete->next;
    toDelete->next->previous = toDelete->previous;
    delete toDelete;
    cSize--;
}

/***
 * ---ITERATOR DEFINITION---
**/

//PRIVATE METHODS

template <class T> Container<T>::Iterator::Iterator(const Container<T>* eContainer, Node* startNode):container(eContainer){
    if(!startNode && container->size()!=0)
        current = container->handle->next;
    else
        current = startNode;
}

template <class T> void Container<T>::Iterator::invalidIterator() const{
    if(!container)
        throw std::domain_error("Iterator not valid");
}

/**
 * @brief Iterator
 */
//PUBLIC METHODS
template <class T> Container<T>::Iterator::Iterator():container(nullptr),current(nullptr){}

/**
 * @brief Iterator
 * @param e
 */
template <class T> Container<T>::Iterator::Iterator(const Iterator& e):container(e.container){ current = e.current;}
template <class T> Container<T>::Iterator::Iterator(const Iterator* e):container(e->container){ current = e->current;}


/**
 * @brief operator --
 */
template <class T> void Container<T>::Iterator::operator--(int) const{
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
template <class T> void Container<T>::Iterator::operator++(int) const{
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
template <class T> const T& Container<T>::Iterator::operator*() const{
    invalidIterator();
    return (current->data);
}
/**
 * @brief getData
 * @return
 */
template <class T> const T& Container<T>::Iterator::getData() const{
    invalidIterator();
    return (current->data);
}

/**
 * @brief operator =
 * @param data
 */
template <class T> void Container<T>::Iterator::operator=(const T* data){
    invalidIterator();
    if(current){
        Node* temp = new Node(*data,current->previous,current->next);
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
template <class T> bool Container<T>::Iterator::operator==(const Iterator& it) const{
    invalidIterator();
    return ((container==it.container) && (current == it.current));
}
/**
 * @brief operator ==
 * @param v
 * @return
 */
template <class T> bool Container<T>::Iterator:: operator==(const T* v) const{
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
template <class T> bool  Container<T>::Iterator::operator!=(const T* v) const{
    return !(*this == v);
}

#endif // CONTAINER_H
