#include<iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

    void reverseInPair(Node* &head, int k)
    {
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;
        while(count <= k){
            Node* temp = curr->next;
            curr->next = NULL;
            prev = curr;
            curr = temp;
            count++;
            Node* link = temp;
        }
    }
};
int main()
{
    
    return 0;
}