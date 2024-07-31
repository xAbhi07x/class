#include <iostream>
using namespace std;

template<typename T>
class vector{
    private:
    T* data;                //pointer to the dynamically allocated array
    int size;               //current number of elements in the vector
    int capacity;           //current size of the vector

    public:
    //constrctors
    vector() : size(0), capacity(2), data(new T[capacity]){}
    vector(int size) : size(size), capacity(size*2), data[new T[capacity]]

    //destructor
    ~vector(){
        delete []data;
    }

    //methods
    void push_back(const T& val){   //importing the refernece of value directly instead of makin shallow copy
        if(size==capacity){
            T* newData = new T[2*capacity]; //dynamic allocation of the vector
            for(int i = 0; i<size; i++){
                newData[i] = data[i];
            }
            delete []data; //releasing the old memory
            data = newData;

        }
        data[size++] = val; //put the value at the end of the vector
    }

    void pop_back(){
        if(size>0) size--;
    }

    int size(){
        return size;
    }

    int empty(){
        return (size==0);
    }

    int capacity(){
        return capacity;
    }

    T& operator[](int index){
        //assuming he is trying to access the valid element
        return data[index];
    }

};