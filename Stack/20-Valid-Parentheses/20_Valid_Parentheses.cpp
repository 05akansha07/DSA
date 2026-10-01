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
class Solution{
public:
    bool isValid(string s){
        stack <char> st;
        if(s.length()%2 !=0)return false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty())return false;
                if(s[i]==')'&&st.top()=='(')
                    st.pop();
                else if(s[i]=='}'&&st.top()=='{')
                    st.pop();
                else if(s[i]==']'&&st.top()=='[')
                    st.pop();
                else 
                    return false;
            }
        }
        return st.empty();
    }
};
int main() {
    Solution solver;

    // Test Case 1: "()" -> Expected: true
    cout << boolalpha;
    cout << "Test 1: " << solver.isValid("()") <<endl;

    // Test Case 2: "()[]{}" -> Expected: true
    cout << "Test 2: " << solver.isValid("()[]{}") <<endl;

    // Test Case 3: "(]" -> Expected: false
    cout << "Test 3: " << solver.isValid("(]") <<endl;

    // Test Case 4: "([])" -> Expected: true
    cout << "Test 4: " << solver.isValid("([])") <<endl;

    // Test Case 5: "([)]" -> Expected: false
    cout << "Test 5: " << solver.isValid("([)]") <<endl;

    return 0;
}
