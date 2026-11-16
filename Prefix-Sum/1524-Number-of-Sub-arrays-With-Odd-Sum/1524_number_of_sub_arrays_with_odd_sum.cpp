#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int  odd = 0;
        int even = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum +=arr[i];
            if(sum % 2 == 0){
                count = (count + odd) % M;
                even++;
            }
            else{
                count = (count + even) % M;
                odd++;
            }
        }
        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 3, 5] -> Expected: 4
    vector<int> arr1 = {1, 3, 5};
    cout << "Test 1: " << solver.numOfSubarrays(arr1) << endl;

    // Test Case 2: [2, 4, 6] -> Expected: 0
    vector<int> arr2 = {2, 4, 6};
    cout << "Test 2: " << solver.numOfSubarrays(arr2) << endl;

    // Test Case 3: [1, 2, 3, 4, 5, 6, 7] -> Expected: 16
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Test 3: " << solver.numOfSubarrays(arr3) << endl;

    return 0;
}