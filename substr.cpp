#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "aabaa";
    cout << s.substr(2,3-2+1) << endl;

    return 0;
}