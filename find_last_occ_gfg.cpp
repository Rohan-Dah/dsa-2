//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int firstOcc(int arr[], int n, int x)
{
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans;

    while(s <= e)
    {
        if(arr[mid] == x){
            ans = mid;
            e = mid - 1;
        }

        else if(arr[mid] > x){
            e = mid - 1;
        }

        else if(arr[mid] < x){
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }

    return ans;

}

int lastOcc(int arr[], int n, int x)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans;
    
    while(s <= e)
    {
        if(arr[mid] == x){
            ans = mid;
            s = mid + 1;
        }

        else if(arr[mid] > x){
            s = mid + 1; 
        }

        else if(arr[mid] < x){
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans(2, -1);
    ans[0] = firstOcc(arr, n, x);
    ans[1] = lastOcc(arr, n, x);

    return ans;

}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends