#ifndef CONTAINER_H
#define CONTAINER_H
template <class T> class Container{
private:
public:
    Container();
    Container(int size);
    Container(Container& c);
};
#endif // CONTAINER_H
