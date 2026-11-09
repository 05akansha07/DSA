#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string intToRoman(int num) {
        static vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        static vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string result = "";
        result.reserve(16);
        for(int i = 0; i < val.size(); i++){
            if(num == 0){
                break;
            }
            int times = num / val[i];
            while(times--){
                result += sym[i];
            }
            num = num % val[i];
        }
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: 3749 -> Expected: "MMMDCCXLIX"
    cout << "Test 1: " << solver.intToRoman(3749) << endl;

    // Test Case 2: 58 -> Expected: "LVIII"
    cout << "Test 2: " << solver.intToRoman(58) << endl;

    // Test Case 3: 1994 -> Expected: "MCMXCIV"
    cout << "Test 3: " << solver.intToRoman(1994) << endl;

    return 0;
}