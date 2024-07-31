#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //default constructor
    Node(){
        data = 0;
        prev = nullptr;
        next = nullptr;
    }

    //constructor with data value
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    //constructor with data + next 
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
        this->prev = nullptr;
    }

    //constructor with data + prev
    Node(int data, Node* prev){
        this->data = data;
        this->next = nullptr;
        this->prev = prev;
    }

    //constructor with data + next + prev
    Node(int data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

        // // Default constructor
        // Node() : data(0), prev(nullptr), next(nullptr) {}

        // // Constructor with data value
        // Node(int data) : data(data), prev(nullptr), next(nullptr) {}

        // // Constructor with data + next
        // Node(int data, Node* next) : data(data), prev(nullptr), next(next) {}

        // // Constructor with data + prev
        // Node(int data, Node* prev) : data(data), prev(prev), next(nullptr) {}

        // // Constructor with data + next + prev
        // Node(int data, Node* next, Node* prev) : data(data), prev(prev), next(next) {}

};

int main(){
    //creating a doubly linked list
    Node * head = new Node(0);
    Node * temp = head;
    for(int i = 1; i<=5; i++){
        Node* newNode = new Node(i);
        newNode->prev = temp;
        temp->next = newNode;
        temp = temp->next;
    }

    // .................................insertion operation

    //insertion at the beginning - inserting 45
    Node* newHead = new Node(45);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;

    //insertion after 4 nodes - inserting 45
    int i = 1;
    temp = head;
    while(i<4){
        temp = temp->next;
    }
    Node *newNode = new Node(45);
    temp->next->prev = newNode;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;

    //insertion at the last - inserting 45
    temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* lastNode = new Node(45);
    lastNode->prev = temp;
    temp->next = lastNode;

    // ..............................deletion operation

    //deleting the first node
    Node* oldHead = head;
    head = head->next;
    head->prev = nullptr;
    delete oldHead;

    //deleting the node after 4 elements
    temp = head;
    int i = 1;
    while(i<4){
        temp=temp->next;
    }
    Node * toDelete = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    delete toDelete;

    //deleting at the end
    temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    Node * lastNode = temp->next;
    temp->next = nullptr;
    delete lastNode;
};