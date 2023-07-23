#include<iostream>
#include<vector>
using namespace std;

void sort012(int arr[], int n)
{
    int count[3] = {0, 0, 0};
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            count[0]++;
        }
        else if(arr[i] == 1){
            count[1]++;
        }
        else{
            count[2]++;
        }
    }

    vector<int> ans;

    for(int i = 0; i<count[0]; i++){
        ans.push_back(0);
    }
    
    for(int i = 0; i<count[1]; i++){
        ans.push_back(1);
    }

    for(int i = 0; i<count[2]; i++){
        ans.push_back(2);
    }
    
    for(int i = 0; i<n; i++)
    {
        arr[i] = ans[i];
    }    

}

int main()
{
    int arr[5] = {0, 2, 1, 2, 0};

    for(int i = 0; i<5; i++){
        cout << arr[i] << " ";
    }
    sort012(arr, 5);
    cout << endl;
    for(int i = 0; i<5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}