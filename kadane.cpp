#include<iostream>
using namespace std;

int maxSub(int arr[], int n)
{
    int sum = 0;
    int maxi = arr[0];

    for(int i = 0; i<n; i++){
        sum = sum + arr[i];

        maxi = max(sum, maxi);
        
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
    
} 


int main()
{
    int arr[5] = {1, 2, 3, -2, 5};
    cout << maxSub(arr, 5) << endl;
    return 0;
}