#include<iostream>
using namespace std;

int maxSum(int arr[], int n)
{
    int maxArray[n];
    for(int i = 0; i<n; i++){
        int maxi = 0;
        for(int j = i; j<n; j++){
            if(maxi + arr[j] > maxi){
                maxi = maxi + arr[j];
            }
        }
        maxArray[i] = maxi;
    }
    
    int maxEle = maxArray[0];
    for(int i = 1; i<n; i++){
        if(maxArray[i] > maxEle){
            maxEle = maxArray[i];
        }
    }

    return maxEle;

    // for(int i = 0; i<n; i++){
    //     cout << maxArray[i] << " ";
    // }
}

int main()
{
    int arr[5] = {5, 4, -1, 7, 8};
    cout << maxSum(arr, 5);

    return 0;
}