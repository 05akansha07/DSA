// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
// An input string is valid if:  
// 1.Open brackets must be closed by the same type of brackets.  
// 2.Open brackets must be closed in the correct order.  
// 3.Every close bracket has a corresponding open bracket of the same type.  
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string a = "[{(}]";
    stack<char> st;
    bool valid = true;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '[' || a[i] == '{' || a[i] == '(')
        {
            st.push(a[i]);
        }
        else
        {
            if (st.empty())
            {
                valid = false;
                break;
            }

            if (a[i] == ']' && st.top() == '[')
            {
                st.pop();
            }
            else if (a[i] == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (a[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
    }
    if (valid && st.empty())
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
}