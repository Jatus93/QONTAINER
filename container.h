#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include "heap.h"
template <class T> class Container{
private:
    heap<T>* head;
public:
    Container();
    Container(int size);
    Container(Container& c);
    bool save(std::string);
    bool load(std::string);
};
#endif // CONTAINER_H
