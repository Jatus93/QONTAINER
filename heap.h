#ifndef HEAP_H
#define HEAP_H


template <class T> class heap
{
private:
    T* value;
    heap* left;
    heap* right;

public:
    heap():value(nullptr),left(nullptr),right(nullptr){}
    heap(T* f_value, heap* f_left=nullptr, heap* f_right=nullptr){
        value = f_value;
        left = f_left;
        right = f_right;
    }
    void addChild(heap *node) {
           if(left == nullptr)
               left = node;
           else {
               node->right = left;
               left = node;
           }
   }
    void merge(heap* ){

    }
    void pop(){
    }
};

#endif // HEAP_H
