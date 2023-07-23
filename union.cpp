// The problem with this doUnion without set is its time complexity. If we do it using set, its more efficient
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void doUnion(int a[], int n, int b[], int m)
{
    vector<int> ans;
    for(int i = 0; i<n; i++){
        ans.push_back(a[i]);
    }

    for(int j = 0; j<m; j++){
        int i = 0;
        for(; i<n; i++){
            if(b[j] == a[i]){
                break;
            }
        }
        if(b[j] != a[i] && i<=n){
            ans.push_back(b[j]);
        }
    }

    int size = ans.size();
    for(int i = 0; i<size; i++){
        cout << ans[i] << " ";
    }
}

int doUnion_size(int a[], int n, int b[], int m)
{
    vector<int> ans;
    for(int i = 0; i<n; i++){
        ans.push_back(a[i]);
    }

    for(int j = 0; j<m; j++){
        int i = 0;
        for(; i<n; i++){
            if(b[j] == a[i]){
                break;
            }
        }
        if(i==n){
            ans.push_back(b[j]);
        }
    }

    int size = ans.size();
    return size;
}

int doUnion_set(int a[], int n, int b[], int m)
{
    unordered_set<int> s;
    for(int i = 0; i<n; i++){
        s.insert(a[i]);
    }
    for(int i = 0; i<m; i++){
        s.insert(b[i]);
    }

    return s.size();
}

int main()
{
    int arr1[6] = {85, 25, 1, 32, 54, 6};
    int arr2[2] = {85, 2};
    // doUnion(arr1, 5, arr2, 3);
    // cout << endl;
    cout << doUnion_size(arr1, 6, arr2, 2) << endl;
    cout << doUnion_set(arr1, 6, arr2, 2) << endl;

    return 0;
}