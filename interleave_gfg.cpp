//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    string temp = A + B;
    int first_length = A.length();
    int second_length = B.length();
    string ans;

    int i = 0;
    int j = first_length;
    int k = 0;
    
    while (i < first_length && j < temp.length()) {
        ans.push_back(temp[i]);
        ans.push_back(temp[j]);
        i++;
        j++;
        k++;
    }
    
    while (j < temp.length()) {
        ans.push_back(temp[j]);
        j++;
        k++;
    }
    
    while (i < A.length()) {
        ans.push_back(temp[i]);
        i++;
        k++;
    }

    return ans == C;
}
        
    

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends