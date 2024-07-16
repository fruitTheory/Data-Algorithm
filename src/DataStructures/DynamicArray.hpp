#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class DynamicArray{
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    DynamicArray();
    ~DynamicArray();

    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t index);
    size_t get_size() const;
    size_t get_capacity() const;
};


template<typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), capacity(0), size(0) {}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
void DynamicArray<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (size > 0) {
        --size;
    }
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
size_t DynamicArray<T>::get_size() const {
    return size;
}

template<typename T>
size_t DynamicArray<T>::get_capacity() const {
    return capacity;
}