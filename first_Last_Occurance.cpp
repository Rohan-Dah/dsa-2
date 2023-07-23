#include<iostream>
#include<vector>
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
    int e = n - 1;
    int ans = -1;
    
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == x) {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < x) {
            s = mid + 1;
        }
        else if (arr[mid] > x) {
            e = mid - 1;
        }
    }

    return ans;
}


vector<int> find(int arr[], int n, int x)
{
    vector<int> ans(2, -1);
    ans[0] = firstOcc(arr, n, x);
    ans[1] = lastOcc(arr, n, x);

    return ans;
}

int main()
{
    cout << "Enter the size of array: " << endl;
    int n; 
    cin >> n;
    int arr[n];
    createArray(arr, n);
    displayArray(arr, n);

    cout << "\nEnter the element to find occurance: " << endl;
    int x;
    cin >> x;

    vector<int> ans;
    ans = find(arr, n, x);
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}