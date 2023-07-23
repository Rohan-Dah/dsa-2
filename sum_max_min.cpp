#include<iostream>
using namespace std;

int maxi(int arr[], int n)
{
    int curr = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i] > curr){
            curr = arr[i];
        }
    }
    return curr;
}

int mini(int arr[], int n)
{
    int cur = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i] < cur){
            cur = arr[i];
        }
    }
    return cur;
}
int main()
{
    int arr[3] = {1, 2, 3};
    cout << maxi(arr, 3) << endl ;
    cout << mini(arr, 3) << endl;

    return 0;
}