#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class queue{
private:
    vector<T> v;
    int front;
    int rear;
public:
    queue(): front(0), rear(0), v(){}
    
    void push(T val){
        v.push_back(val);
        rear++;
    }

    int top(){
        if(front==rear) return null;
        return v[front];
    }

    void pop(){
        if(front>=rear) return;
        front++;
    }

    int size(){
        if(front==rear) return 0;
        return (rear-front);
    }
};
