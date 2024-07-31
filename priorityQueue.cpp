#include <iostream>
#include <vector>
using namespace std;


class priorityQueue{
    private:
    vector<int> v;

    public:
    priorityQueue(): v(){}

    int leftChild(int i){
        return (2*i+1);
    }

    int rightChild(int i){
        return (2*i+2);
    }

    int parent(int i){
        return (i-1)/2;
    }

    void insert(int val){
        v.push_back(val);
        shiftUp((v.size()-1));
    }

    void shiftUp(int i){
        while(i!=0 && v[parent(i)]<v[i]){
            int father = parent(i);
            swap(v[father], v[i]);
            i = father;
        }
    }

    void remove(){
        if(v.size()==0) return;
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        if(!v.empty()){
            shiftDown(0);
        }
    }

    void shiftDown(int i){
        while(true){
            int lc = leftChild(i);
            int rc = rightChild(i);

            if(lc>=v.size()) break;
            int maxChild = (rc<v.size() && v[rc]>v[lc]) ? rc : lc;
            if(v[maxChild]<=v[i]) break;
            swap(v[maxChild], v[i]);
            i = maxChild;
        }
    }

};