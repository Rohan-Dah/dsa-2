#include<iostream>
using namespace std;

string rev_string(string str)
{
    int n = str.size();
    for(int i = 0, j = n-1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

int main()
{
    cout << "Enter the string: " << endl;
    string str;
    getline(cin, str);
    cout << "Before reverse: " << str << endl;
    string rev = rev_string(str);
    cout << "After reverse: " << rev << endl;
   
    
    return 0;
}