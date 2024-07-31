#include <vector>
#include <iostream>
using namespace std;


class Node{
public:
    int val;
    vector<Node*> children;
    Node(): val(0), children(){}
    Node(int data): val(data), children(){}
};


class GT{
private:
    Node* root;
public:
    GT(): root(nullptr){}
    GT(int data){
        root = new Node(data);
    }

    void traverse(Node * root){
        if(root==nullptr) return;
        cout<< root->val;
        for(int i= 0; i<root->children.size(); i++){
            traverse(root->children[i]);
        }
    }

    void traverse(){traverse(root);}

    Node* find(int parent, Node* root){
        if(root->val==parent) return root;
        for(int i= 0; i<root->children.size(); i++){
            Node* temp = find(parent, root->children[i]);
            if(temp!=nullptr) return temp;
        }
        return nullptr;
    }

    void Add(int parent, int child){
        Node* father = find(parent, root);
        //if there is no parent I am adding it to the root's child
        if(father==nullptr){
            Node * newChild = new Node(child);
            root->children.push_back(newChild);
            return;
        }
        Node* newChild = new Node(child);
        father->children.push_back(newChild);
        return;
    }
};