#include <iostream>
#include <vector>
using namespace std;


class priorQueue{
    private:
    vector<pair<int, int>> v;

    public:
    int parent(int i){
        return (i-1)/2;
    }

    int leftChild(int i){
        return (2*i+1);
    }

    int rightChild(int i){
        return (2*i+2);
    }

    void insert(int first, int second){
        v.push_back({first, second});
        shiftUp(v.size()-1);
    }

    void shiftUp(int i){
        while(i!=0){
            int father = parent(i);
            if(v[father].first > v[i].first) return;
            if(v[father].first == v[i].first){
                if(v[father].second >= v[i].second) return;
            }
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
            int maxChild = (rc<v.size() && v[rc].first>v[lc].first) ? rc : lc;
            if(v[maxChild]<=v[i]) break;
            swap(v[maxChild], v[i]);
            i = maxChild;
        }
    }

};