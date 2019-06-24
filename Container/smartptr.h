/**
  * @file smartptr.h
  * @class SmartPtr<T>
  * @brief Template class that is a pointer wrapper which enables to compare two objects dereferencing them
  */
#ifndef SMARTPTR_H
#define SMARTPTR_H
template <class T> class SmartPtr{
private:
    T* pointer;
public:
    /**
     * @brief SmartPtr
     * @param mPointer
     */
    SmartPtr(T* mPointer = nullptr);
    /**
     * @brief SmartPtr
     * @param sptr
     */
    SmartPtr(const SmartPtr<T>& sptr);
    /**
     * @brief SmartPtr
     * @param sptr
     */
    SmartPtr(const SmartPtr<T>&& sptr);
    /**
     * @brief operator *
     * @return
     */
    T& operator*() const;

    /**
     * @brief operator ->
     * @return
     */
    T* operator->() const;

    /**
     * @brief operator =
     * @param sptr
     * @return
     */
    void operator=(T* sptr);

    /**
     * @brief operator =
     * @param sptr
     * @return
     */
    void operator=(const SmartPtr<T>& sptr);

    /**
     * @brief operator ==
     * @param sptr
     * @return
     */
    bool operator==(const SmartPtr<T>& sptr) const;
    /**
     * @brief operator ==
     * @param sptr
     * @return
     */
    bool operator==(const T* sptr) const;
    /**
     * @brief operator =
     * @param sptr
     * @return
     */
    bool operator!=(const SmartPtr<T>& sptr) const;
    /**
     * @brief operator ==
     * @param sptr
     * @return
     */
    bool operator!=(const T* sptr) const;

    /**
     * @brief isNull
     * @return
     */
    bool isNull() const;

    ~SmartPtr();
};

template <class T> SmartPtr<T>::SmartPtr(T* mPointer):pointer(mPointer){}

template <class T> SmartPtr<T>::SmartPtr(const SmartPtr<T>& sptr){
    pointer = sptr.pointer->clone();
}

template <class T> SmartPtr<T>::SmartPtr(const SmartPtr<T>&& sptr):SmartPtr(sptr.pointer->clone()){};

template <class T> T& SmartPtr<T>::operator*() const{
    return *pointer;
}

template <class T> T* SmartPtr<T>::operator->() const{
    return pointer;
}

template <class T> void SmartPtr<T>::operator=(T* sptr){
    pointer = sptr;
}

template <class T> void SmartPtr<T>::operator=(const SmartPtr<T>& sptr){
    pointer = sptr.pointer;
}

template <class T> bool SmartPtr<T>::operator==(const SmartPtr<T>& sptr) const{
    if(sptr.pointer == pointer)
        return true;
    return ((*this) == sptr.pointer);
}
template <class T> bool SmartPtr<T>::operator==(const T* ptr) const{
    if(ptr == pointer)
        return true;
    if(ptr == nullptr)
        return false;
    return (*ptr == *pointer);
}
template <class T> bool SmartPtr<T>::operator!=(const SmartPtr<T>& sptr) const{
    return !((*this) == sptr);
}

template <class T> bool SmartPtr<T>::operator!=(const T* ptr) const{
    return !((*this) == ptr);
}

template <class T> bool SmartPtr<T>::isNull() const{
    return (pointer == nullptr);
}

template <class T> SmartPtr<T>::~SmartPtr(){
    if(pointer)
        delete pointer;
}


#endif // SMARTPTR_H
