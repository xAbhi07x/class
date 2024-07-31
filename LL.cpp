#include <iostream>
#include<forward_list>
using namespace std;

//singly linked list class
class Node{
    public:
    int data;
    Node* next;

    
    //default constructor
    Node(){
        data = 0;
        next = nullptr;
    }

    //constructor with data input
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    //constructor with data input and next pointer
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

int main(){
    Node * head = new Node(0);
    Node * temp = head;
    for(int i = 1; i<=5; i++){
        Node * newNode = new Node(i);
        temp->next = newNode;
        temp = temp->next;
    }

    // ............insertion operation

    //inserting 7 at the beginning
    Node * newHead = new Node(7);
    newHead->next = head;
    head = newHead;

    //inserting 7 at the middle (say after first 3 node)
    Node* newNode = new Node(7);
    temp = head;
    int i = 1;
    while(i<3){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    //inserting 7 at the end
    Node* lastNode = new Node(7);
    temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = lastNode;


    // ................... deletion operation

    //deleting the first element 
    Node* oldHead = head;
    head = head->next;
    delete oldHead;


    //deleting the element after 3 nodes
    temp = head;
    i = 1;
    while(i<3){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    //deleting the last element
    temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    Node* lastToDelete = temp->next;
    temp->next = nullptr;
    delete lastToDelete;
}