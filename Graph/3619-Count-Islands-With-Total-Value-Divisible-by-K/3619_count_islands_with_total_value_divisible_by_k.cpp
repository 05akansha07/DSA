#include <iostream>
#include <vector>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    int m , n;
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    long long dfs(int i, int j, vector<vector<int>> &grid){
        long long sum = grid[i][j];
        grid[i][j] = 0;
        for(vector<int> &dic:direction){
            int i_ = i + dic[0];
            int j_ = j + dic[1];
            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0){
                sum += dfs(i_, j_, grid);
            }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    long long sum = dfs(i,j,grid);
                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 2
    vector<vector<int>> g1 = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };
    cout << "Test 1: " << solver.countIslands(g1, 5) << endl;

    // Test Case 2: Expected: 6
    vector<vector<int>> g2 = {
        {3, 0, 3, 0},
        {0, 3, 0, 3},
        {3, 0, 3, 0}
    };
    cout << "Test 2: " << solver.countIslands(g2, 3) << endl;

    return 0;
}