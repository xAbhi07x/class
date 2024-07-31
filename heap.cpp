#include<vector>
#include<iostream>
using namespace std;

class heap{
private:
    vector<int> v;
public:
    heap(): v(){}

    void updateInsert(){
        int childIdx = v.size()-1;
        int parentIdx = (childIdx-1)/2;

        //swap if it is less in value
        while( childIdx != 0 && v[parentIdx]>v[childIdx]){
            int temp = v[parentIdx];
            v[parentIdx] = v[childIdx];
            v[childIdx] = temp;

            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }
    
    void insert(int val){
        v.push_back(val);
        updateInsert();
    }

    void Delete(){
        if(v.size()==0) return;
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        if(!v.empty()){
            updateDelete();
        }
    }

    void updateDelete(){
        int parent = 0;
        int size = v.size();
        while (true) {
            int child1 = 2 * parent + 1;
            int child2 = 2 * parent + 2;
            if (child1 >= size) break; // No children
            int minChild = (child2 < size && v[child2] < v[child1]) ? child2 : child1;
            if (v[parent] <= v[minChild]) break;
            swap(v[parent], v[minChild]);
            parent = minChild;
        }
    }

    void display(){
        for(int val : v){
            cout << val << " ";
        }
    }
};