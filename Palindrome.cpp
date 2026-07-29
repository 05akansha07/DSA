#include <iostream>
using namespace std;
int main()
{
    string s = "madam";
    int n = s.length();
    //int n = s.size();
    bool flag = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}