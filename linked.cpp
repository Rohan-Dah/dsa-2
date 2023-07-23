// creating andd traversing through linked list

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}

void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAfter3(Node* &head, int val)
{
    Node* n = new Node(val);
    Node* temp = head;
    while(temp->data != 3){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void reverse(Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int main()
{
    Node* head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 1);
    insertAfter3(head, 8);
    reverse(head);
    display(head);
    return 0;
}