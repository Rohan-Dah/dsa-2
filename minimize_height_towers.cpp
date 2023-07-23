#include<iostream>
#include<algorithm>
using namespace std;

int minHeight(int arr[], int n, int k)
{
    sort(arr, arr+n);

    if(n == 1) return 0;

    int diff = arr[0] - arr[n-1];

    int maxi, mini;
    for(int i = 1; i<n; i++){
        maxi = max(arr[i-1]+k, arr[n-1]-k);
        mini = min(arr[0])
    }

}

int main()
{
    int arr[4] = {1, 5, 8, 10};

    return 0;
}