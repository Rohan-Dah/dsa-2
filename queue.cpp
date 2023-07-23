#include<iostream>
using namespace std;
#define n 100

class queue
{
    int* arr;
    int front;
    int back;
public:
    queue(){
        front = -1;
        back = -1;
        arr = new int[n];
    }

    void enqueue(int val)
    {
        if(front == -1 || front>back){
            front = 0;
        }

        back++;
        arr[back] = val;
    }

    void dequeue()
    {
        if(front > back){
            cout << "Empty queue" << endl;
        }
        front++;
    }

    int peek()
    {
        if(front>back){
            cout << "Empty queue" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return front>back;
    }

    void print()
    {
        for(int i = front; i<back; i++){
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    queue q;
    q.enqueue(5);
    q.enqueue(6);
    cout << q.peek() << endl;
    q.dequeue();
    cout << endl;
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;


    return 0;
}