#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int data) : val(data), left(nullptr), right(nullptr) {}
    Node(int data, Node *left, Node *right) : val(data), left(left), right(right) {}
};

class binaryTree{
private:
    Node *root;

public:
    // implementing constructors
    binaryTree() : root(nullptr) {}

    binaryTree(int data){
        root = new Node(data);
    }

    binaryTree(int data, Node *left, Node *right){
        root = new Node(data, left, right);
    }

    //  3 kinds of traversel - preorder, inorder, postorder

    void preTrav(){
        preTrav(root);
        cout<< endl;
    }

    // preorder
    void preTrav(Node *root){
        if (root == nullptr) return;
        cout << root->val;
        preTrav(root->left);
        preTrav(root->right);
    }

    //....how are we gonna add into the tree? 
    //.... 1. if the element already exist - then don't do anything
    //.... 2. if the element don't exist - add it (but where?)


    //finding if the element already exist?
    Node * find(int data, Node* root){
        if(root==nullptr) return nullptr;
        if(root->val == data) return root;

        Node* foundNode = find(data, root->left);
        if(foundNode==nullptr) foundNode = find(data, root->right);
        return foundNode;
    }

    //adding the element in the manner such that left<root<data

    void addNodeHelper(int data, Node* root){
        //agar data root ke value se chota ya equal he to root->left mein daal do
        if(root->val>=data){
            if(root->left==nullptr){
                root->left = new Node(data);
                return;
            }
            addNodeHelper(data, root->left);
        }else{
            if(root->right==nullptr){
                root->right = new Node(data);
                return;
            }
            addNodeHelper(data, root->right);
        }
    }

    void addNode(int data){
        if(root==nullptr){
            root = new Node(data);
            return;
        }

        Node * foundNode = find(data, root);
        if(foundNode!=nullptr) return;

        addNodeHelper(data, root);
    }
    
};


int main() {
    binaryTree tree;
    tree.addNode(10);
    tree.addNode(5);
    tree.addNode(20);
    tree.addNode(3);
    tree.addNode(7);
    tree.addNode(15);
    tree.addNode(25);
    tree.preTrav();

    return 0;
}