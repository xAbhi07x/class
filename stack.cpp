#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class stack{
private:
    vector<T> v;
public:
    stack(): v(){}

    void push(T val){
        v.push_back(val);
    }

    int top(){
        if(v.size()==0) return -1;
        return v[v.size()-1];
    }

    void pop(){
        if(v.empty()) return;
        v.pop_back();
    }

    int size(){
        return v.size();
    }
};

int main(){
    stack<char> st;
    st.push(1); 
    st.push(2); 
    st.push(3); 
    st.push(4); 
    st.push(5); 
    st.push(6);

    int top = st.top();
    cout << top << " ";
    st.pop();
    top = st.top(); 
    cout << top << " ";
    st.pop();
    top = st.top(); 
    cout << top << " ";
}