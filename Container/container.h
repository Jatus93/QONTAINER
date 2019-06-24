/**
  * @file container.h
  * @class Container<T>
  * @brief Container<T> is a circular data structure
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <stdexcept>
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
        * Complete constructor
        * @brief Node
        * @param fData
        * @param fPrevious
        * @param fNext
        */
        Node(const T& fData,Node* fPrevious,Node* fNext):first(false){
            data = fData;
            previous = fPrevious;
            next = fNext;
        }

        /**
         *
         * Copy constructor
         *
         * @brief Node
         * @param c
         */
        Node(const Node& c):first(c.first){
            data = c.data;
            this->previous = c.previous;
            this->next = c.next;
        }
        /**
         *
         * Default constructor should be used only as first node
         *
         * @brief Node
         */
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
     * private method that returns the element at i posizione
     * @brief getElement
     * @param i
     * @return returns the i element
     */
    Node* getElement(const int& i) const;
    /**
     *
     * private method that returns the element at i position
     * the method starts from the end of the chain
     *
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
     *
     * private method that returns the element at i position
     * the method starts from the start of the chain
     *
     * @brief insert
     * @param node
     * @param value
     */
    void insert(Node* node, const T& value);

    /**
     *
     * private method that delete the passed element and rebuild the chain
     *
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
         *
         * constructor recallabe only from the the superior class
         *
         * @brief Iterator
         * @param eContainer
         * @param startNode
         */
        Iterator(const Container<T>* eContainer, Node* startNode = nullptr);

        void invalidIterator() const;
    public:

        /**
         *
         * Base constructor
         *
         * @brief Iterator
         */

        Iterator();

        /**
         *
         * Copy constructors
         *
         * @brief Iterator
         * @param e
         */
        Iterator(const Iterator& e);
        Iterator(const Iterator* e);


        /**
         * moves the iterator backwards
         * @brief operator --
         */
        Iterator operator--(int) const;
        /**
         * moves the iterator forward
         * @brief operator ++
         */
        Iterator operator++(int) const;

        /**
         * dereference the content of Node T
         * @brief operator *
         * @return T
         */
        T& operator*() const;

        /**
         * returns the content of Node
         * @brief getData
         * @return T
         */
        T& getData() const;

        /**
         * replace the content of node
         * @brief operator =
         * @param data
         */
        void operator=(const T* data);
        /**
         * compares the current node content iterator with the one in argument
         * @brief operator ==
         * @param it
         * @return
         */
        bool operator==(const Iterator& it) const;
        /**
         * compares the current node content iterator with the one in argument
         * @brief operator ==
         * @param v
         * @return
         */
        bool operator==(const T* v) const;
        /**
         * compares the current node content iterator with the one in argument
         * @brief operator !=
         * @param v
         * @return
         */
        bool operator!=(const T* v) const;
    };
    /**
     * Base constructor
     * @brief Container
     */
    Container();
    /**
     * Copy constructor
     * does not perfom a deepcopy
     * @brief Container
     * @param c
     */
    Container(const Container<T>& c);
    /**
     * Copy constructor
     * does not perfom a deepcopy
     * @brief Container
     * @param c
     */
    Container(const Container<T>* c);

    /**
     * clones the current Container
     * does perfom a deepcopy
     * @brief clone
     * @return
     */
    Container<T>* clone() const;

    /**
     * insert T in the front of the data structure
     * @brief push_front
     * @param value
     */

    void pushFront(const T& value);

    /**
     * insert T in the back of the data structure
     * @brief push_back
     * @param value
     */
    void pushBack(const T& value);
    /**
     * returns the iterator for the T wanted
     * @brief search
     * @param value
     * @return
     */
    const Iterator& search(const T& value) const;

    /**
     * insert T in the i position
     * @brief insert
     * @param i
     * @param value
     */
    void insert(const int i, const T& value);

    /**
     * insert T after the iterator
     * @brief insertAfterIterator
     * @param it
     */
    void insertAfterIterator(const Iterator& it, const T& value);

    /**
     * returns the content of the node in index position
     * @brief operator []
     * @param index
     * @return
     */
    T& operator[](int index) const;

    /**
     * deletes the element at i position.
     * if T is a pointer does not perfrom deep delete;
     * @brief deleteElementAt
     * @param i
     */
    void deleteElementAt(int i);

    /**
     * deletes the element at the iterator position if is valid.
     * if T is a pointer does not perfrom deep delete;
     * @brief deleteElementAt
     * @param it
     */
    void deleteElementAt(const Iterator& it);
    /**
     * returns the iterator at the start
     * @brief getIterator
     * @return
     */
    Iterator* getIterator();
    /**
     * returns the const iterator at the start
     * @brief getConstInterator
     * @return const Iterator
     */

    const Iterator* getConstIterator() const;

    /**
     * returns the const iterator at the index
     * @brief getConstInteratorAt
     * @param index
     * @return const Iterator
     */
    const Iterator* getConstIteratorAt(int index =0) const;

    /**
     * returns the iterator at the index position
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

    /**
     * @brief clear
     */
    void clear();

    ~Container();
};

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

template <class T> T& Container<T>::operator[](int index) const{
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

template <class T> void Container<T>::clear(){
    while(cSize>0){
        deleteElementAt(cSize-1);
    }
}

template <class T> Container<T>::~Container(){
    clear();
    delete handle;
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


//PUBLIC METHODS
template <class T> Container<T>::Iterator::Iterator():container(nullptr),current(nullptr){}

template <class T> Container<T>::Iterator::Iterator(const Iterator& e):container(e.container){ current = e.current;}
template <class T> Container<T>::Iterator::Iterator(const Iterator* e):container(e->container){ current = e->current;}

template <class T> typename Container<T>::Iterator Container<T>::Iterator::operator--(int) const{
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

template <class T> typename Container<T>::Iterator Container<T>::Iterator::operator++(int) const{
    invalidIterator();
    if(current){
        if(!current->next->first)
            current = current->next;
        else
            current = nullptr;
    }else{
        current = container->handle->next;
    }
    return this;
}

template <class T> T& Container<T>::Iterator::operator*() const{
    invalidIterator();
    return (current->data);
}

template <class T> T& Container<T>::Iterator::getData() const{
    invalidIterator();
    return (current->data);
}

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

template <class T> bool Container<T>::Iterator::operator==(const Iterator& it) const{
    invalidIterator();
    return ((container==it.container) && (current == it.current));
}

template <class T> bool Container<T>::Iterator:: operator==(const T* v) const{
    invalidIterator();
    if((current == nullptr) && (v == nullptr))
        return true;
    return (&current->data == v);
}

template <class T> bool  Container<T>::Iterator::operator!=(const T* v) const{
    return !(*this == v);
}

#endif // CONTAINER_H
