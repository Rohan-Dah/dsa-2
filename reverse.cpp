//Q1 Array - Reverse

#include<iostream>
using namespace std;

void createArray(int arr[], int n)
{
    cout << "Enter the elements: " << endl;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n)
{
    cout << "\nYour elements are: " << endl;
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverse(int arr[], int n)
{
    for(int i = 0, j=n-1; i<j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    cout << "Enter the array size: " << endl;
    int n;
    cin >> n;
    int arr[n];
    createArray(arr, n);
    displayArray(arr, n);
    reverse(arr, n);
    displayArray(arr, n);

    return 0;
}