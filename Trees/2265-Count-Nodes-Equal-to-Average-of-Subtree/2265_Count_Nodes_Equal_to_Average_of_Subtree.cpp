#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int matchingNode = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int currentSum = left.first + right.first + root->val;
        int currentCount = left.second + right.second + 1;

        if (currentSum / currentCount == root->val) {
            matchingNode++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNode = 0;
        dfs(root);
        return matchingNode;
    }
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    /*
     * Constructing Tree for Example 1:
     *         4
     *       /   \
     *      8     5
     *     / \     \
     *    0   1     6
     */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution solver;
    int result = solver.averageOfSubtree(root);

    cout << "Test Case 1 Output: " << result << " (Expected: 5)" << endl;

    deleteTree(root);
    return 0;
}