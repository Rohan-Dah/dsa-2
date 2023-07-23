#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
   sort(arr+l, arr+r+1);
   return arr[k-1];


}

int main()
{
    int arr[5] = {7, 10, 4, 20, 15};
    // int ans = kthSmallest(arr, 0, 4, 4);
    // cout << ans << endl;
    cout << kthSmallest(arr, 0, 4, 4) << endl;

    return 0;
}