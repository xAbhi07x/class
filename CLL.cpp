#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node() : data(0), next(nullptr){}
    Node(int data): data(data), next(nullptr){}
    Node(int data, Node* next): data(data), next(next){}
};


int main(){
    //creating a circular linked list (singly)
    Node * head = new Node(0);
    Node * temp = head;
    for(int i = 1; i<=5; i++){
        Node * newNode = new Node(i);
        temp->next = newNode;
        temp = temp->next;
    }
    temp->next = head;

    //keeping the last node so that i don't have to traverse it to find it 
    Node* endNode = temp;

    // ..................................... inserion operations

    // inserting at the beginning - (18)
    Node * newHead = new Node(18);
    newHead->next = head;
    head = newHead;
    endNode->next = head;

    //inserting 18 at the middle (say after first 3 node)
    Node* newNode = new Node(18);
    temp = head;
    int i = 1;
    while(i<3){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    //inserting 18 at the end (it is same as inserting in the beginning)
    Node* lastNode = new Node(18);
    lastNode->next = head;
    endNode->next = lastNode;
    endNode = lastNode; //updating the last Node


    // ............................................. deletion operation

    //deleting the first element 
    Node* oldHead = head;
    head = head->next;
    endNode->next = head;
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
    while(temp->next!=endNode){
        temp = temp->next;
    }

    Node* oldEndNode = endNode;
    temp->next = head;
    endNode = temp;
    delete oldEndNode;
}