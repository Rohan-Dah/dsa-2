#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cout << "Enter strings: " << endl;
    string s1, s2;
    cin >> s1 >> s2;

    string temp = s1 + s2;
    cout << temp << endl;
    string sub;
    cout << "Enter string you want to check: " << endl;
    cin >> sub;
    if(temp.find(sub) != string::npos)
    {
        cout << "True";
    }
    else{
        cout << "False";
    }

    return 0;
}