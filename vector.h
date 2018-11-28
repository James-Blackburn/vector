#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <initializer_list>

template <typename T>
class vector{
public:
    typedef size_t size_type;
    typedef T* iterator;
private:
    T* dynamicArray;
    size_type vSize;
    size_type vCapacity;
    size_type vShift;
public:
    void push_back(const T&);
    void push_front(const T&);
    void pop_back();
    void reserve(int);
    void resize(size_type);
    inline bool empty() const;
    inline void shrink_to_fit();
    inline iterator begin();
    inline iterator end();
    inline T& back();
    inline T& front();
    inline size_type size() const;
    inline size_type capacity() const;
    inline T& operator[](size_type pos);
    vector();
    vector(std::initializer_list<T>);
    ~vector();
};

template <typename T>
vector<T>::vector() :
    dynamicArray(nullptr),vSize(0),vCapacity(0),vShift(0){
}

template <typename T>
vector<T>::vector(std::initializer_list<T> ls)
    : vSize(ls.size()),vCapacity(ls.size()*2),vShift(0) {
    dynamicArray = new T[ls.size()];
    vector<T>::size_type index = 0;
    for (T element : ls){
        dynamicArray[index] = element;
        index++;
    }
}

template <typename T>
vector<T>::~vector(){
    delete[] dynamicArray;
}

template <typename T>
inline typename vector<T>::iterator vector<T>::begin() {
    return dynamicArray;
}

template <typename T>
inline typename vector<T>::iterator vector<T>::end() {
    return dynamicArray+size();
}

template <typename T>
inline T& vector<T>::back() {
    return dynamicArray[vSize-1];
}

template <typename T>
inline T& vector<T>::front() {
    return dynamicArray[0];
}

template <typename T>
inline typename vector<T>::size_type vector<T>::size() const{
    return vSize;
}

template <typename T>
inline typename vector<T>::size_type vector<T>::capacity() const{
    return vCapacity;
}

template <typename T>
inline T& vector<T>::operator[](size_type pos){
    return dynamicArray[pos];
}

template <typename T>
inline void vector<T>::shrink_to_fit(){
    int unusedCapacity = vCapacity-vSize;
    reserve(-unusedCapacity);
}

template <typename T>
inline bool vector<T>::empty() const{
    return vSize==0;
}

template <typename T>
void vector<T>::push_back(const T& data){
    ++vSize;
    if (vCapacity <= vSize){
        reserve(vCapacity);
    }
    dynamicArray[vSize-1] = data;
}


template <typename T>
void vector<T>::push_front(const T& data){
    ++vSize;
    vShift = 1;
    if (vCapacity <= vSize){
        reserve(vCapacity);
    } else{
        reserve(0);
    }
    dynamicArray[0] = data;
    vShift = 0;
}

template <typename T>
void vector<T>::pop_back(){
    vSize--;
    vCapacity--;
}


template <typename T>
void vector<T>::reserve(int newCapacity){
    vCapacity = vCapacity + newCapacity;
    T* newArray = new T[vCapacity];
    for (size_type i=0; i<vSize-1; ++i){
        newArray[i+vShift] = dynamicArray[i];
    }
    delete[] dynamicArray;
    dynamicArray = newArray;
}

#endif // VECTOR_H_INCLUDED
