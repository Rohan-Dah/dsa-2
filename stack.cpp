#include<iostream>
using namespace std;
#define n 100

class stack{
    int* arr;
    int top;
public:
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int val){
        if(top == n-1){
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(top == -1){
            cout << "Empty stack" << endl;
            return;
        }
        top--;
    }

    void print(){
        for(int i = 0; i<=top; i++){
            cout << arr[i] << " ";
        }
    }

    int Top(){
        if(top == -1){
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
};

int main()
{
    stack s;
    s.push(2);
    cout << s.Top() << endl;
    s.push(3);
    s.print();
    s.pop();
    cout << endl;
    
    cout << s.Top() << endl;
    return 0;
}