#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    const vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int toDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int totalDays = day;
        for (int m = 0; m < month - 1; m++) {
            totalDays += daysInMonth[m];
        }
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = toDayOfYear(arriveAlice);
        int endAlice = toDayOfYear(leaveAlice);
        int startBob = toDayOfYear(arriveBob);
        int endBob = toDayOfYear(leaveBob);

        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);

        return max(0, overlapEnd - overlapStart + 1);
    }
};

int main() {
    Solution solver;

    // Test Case 1: "08-15" to "08-18" and "08-16" to "08-19" -> Expected: 3
    cout << "Test 1: " 
         << solver.countDaysTogether("08-15", "08-18", "08-16", "08-19") << endl;

    // Test Case 2: "10-01" to "10-31" and "11-01" to "12-31" -> Expected: 0
    cout << "Test 2: " 
         << solver.countDaysTogether("10-01", "10-31", "11-01", "12-31") << endl;

    return 0;
}