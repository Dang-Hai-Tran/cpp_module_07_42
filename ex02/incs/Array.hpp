#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <string>

template <typename T>
class Array {
   private:
    T* _arr;
    unsigned int _size;

   public:
    Array() : _arr(NULL), _size(0){};
    Array(unsigned int size) : _arr(new T[size]), _size(size){};
    Array(Array const& other) : _arr(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_arr[i] = other._arr[i];
        }
    };
    ~Array() { delete[] this->_arr; };

    Array& operator=(Array const& other) {
        if (this->_size != other._size) {
            this->_size = other._size;
            delete[] this->_arr;
            this->_arr = new T[other.size];
        }
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_arr[i] = other._arr[i];
        }
        return *this;
    };

    T& operator[](int index) {
        if (index < 0 || index > (int)this->_size - 1)
            throw MyException("Index is out of bounds.");
        return this->_arr[index];
    };
    class MyException : public std::exception {
       public:
        MyException(const std::string& message) : _message(message) {}
        virtual ~MyException() throw() {}
        virtual const char* what() const throw() { return _message.c_str(); }

       private:
        std::string _message;
    };
    unsigned int size() { return this->_size; };
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& obj) {
    for (unsigned int i = 0; i < obj.size(); i++) {
        os << "[" << obj[i] << "]";
    }
    return os;
}

#endif
