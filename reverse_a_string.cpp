#include <iostream>
using namespace std;
int main()
{
    string s = "paper";
    char temp;
    int n = s.length();
    int left = 0, right = n - 1;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
    cout<<s;
}