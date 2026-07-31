//check wheather the strings are is anagram
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s1 = "apple";
    string s2 = "pplea";

    if(s1.length() != s2.length())
    {
        cout << "The strings are not anagrams.";
    }
    else
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if(s1 == s2)
            cout << "The strings are anagrams.";
        else
            cout << "The strings are not anagrams.";
    }
}