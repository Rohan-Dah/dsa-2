#include<iostream>
#include<vector>
using namespace std;

int returnSizeIfPalin(string s)
{
    int n = s.size();
    for(int i = 0, j = n-1; i<j; i++, j--){
        if(s[i] != s[j]){
            return 0;
        }
    }
    return n;
}

string longestPalin(string s)
{
    int n = s.size();
    int arr[n][n];
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            arr[i][j] = returnSizeIfPalin(s.substr(i, j - i + 1));
        }
    }

    int max = arr[0][0];
    int start, end;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
                start = i;
                end = j;
            }
        }
    }

    return s.substr(start, end - start + 1);
}

int main()
{
    string s = "aabaa";
    cout << longestPalin(s) << endl;
    return 0;
}