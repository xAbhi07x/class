#include<vector>
#include <iostream>
using namespace std;

class binaryTree{
    private:
    vector<int> v;

    public:
    binaryTree(): v() {}
    binaryTree(int data){
        v.push_back(data);
    }

    int findIndex(int data){
        int idx = -1;
        for(int i = 0; i<v.size(); i++){
            if(v[i]==data) idx = i;
        }
        return idx;
    }

    int leftChild(int data){
        int idx = findIndex(data);
        if(idx!=-1){
            if(2*idx+1<v.size()) return v[2*idx+1];
        }
        return -1;
    }

    int rightChild(int data){
        int idx = findIndex(data);
        if(idx!=-1 && idx>0){
            if(2*idx+2<v.size()) return v[2*idx+2];
        }
        return -1;
    }

    int parent(int data){
        int idx = findIndex(data);
        if(idx!=-1){
            return v[((idx-1)/2)];
        }
        return -1;
    }

    void add(int data){
        v.push_back(data);
    }

    void preTrav(int idx = 0){
        if(v.size()==0 || idx>=v.size()) return;

        cout<< v[idx];
        if(2*idx+1<v.size()) preTrav(2*idx+1);
        if(2*idx + 2<v.size()) preTrav(2*idx+2);
    }
};