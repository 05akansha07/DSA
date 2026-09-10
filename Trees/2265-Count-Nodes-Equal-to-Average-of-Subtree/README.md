# 2265. Count Nodes Equal to Average of Subtree

**Difficulty:** Medium  
**Topics:** Tree, Depth-First Search, Binary Tree  
**Language:** C++

---

## Problem Statement

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

**Note:**
- The **average** of $n$ elements is the sum of the $n$ elements divided by $n$ and rounded down to the nearest integer.
- A **subtree** of `root` is a tree consisting of `root` and all of its descendants.

---

## Examples

### Example 1:

```
        4
      /   \
     8     5
    / \     \
   0   1     6
```

- **Input:** `root = [4, 8, 5, 0, 1, null, 6]`
- **Output:** `5`
- **Explanation:**
  - For the node with value `4`: The average of its subtree is `(4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4`.
  - For the node with value `5`: The average of its subtree is `(5 + 6) / 2 = 11 / 2 = 5`.
  - For the node with value `0`: The average of its subtree is `0 / 1 = 0`.
  - For the node with value `1`: The average of its subtree is `1 / 1 = 1`.
  - For the node with value `6`: The average of its subtree is `6 / 1 = 6`.

### Example 2:

- **Input:** `root = [1]`
- **Output:** `1`
- **Explanation:** For the node with value `1`: The average of its subtree is `1 / 1 = 1`.

---

## Constraints

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`

---

## Intuition & Approach

### Key Observation:
To calculate the average of any subtree rooted at `root`, we need two values from its descendants:
1. The **sum** of all node values in that subtree.
2. The **total count** of nodes in that subtree.

Since the parent node depends on the results of both its left and right subtrees, a **Bottom-Up Post-Order Traversal (DFS)** is the optimal strategy:
1. Recursively compute `(leftSum, leftCount)` for `root->left`.
2. Recursively compute `(rightSum, rightCount)` for `root->right`.
3. Combine the results:
   - $\text{currentSum} = \text{leftSum} + \text{rightSum} + \text{root}->\text{val}$
   - $\text{currentCount} = \text{leftCount} + \text{rightCount} + 1$
4. Check if the integer division `currentSum / currentCount == root->val`. If so, increment the answer counter.
5. Return the pair `(currentSum, currentCount)` to the parent node.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$  
  Every node in the binary tree is visited exactly once during the post-order DFS traversal.
- **Space Complexity:** $\mathcal{O}(H)$  
  Where $H$ is the height of the tree, corresponding to the maximum depth of the recursive call stack. In the worst case (skewed tree), $H = \mathcal{O}(N)$; in the best case (balanced tree), $H = \mathcal{O}(\log N)$.

---

## C++ Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int matchingNode = 0;

    // Helper function that returns {subtree_sum, subtree_node_count}
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        // Post-order traversal: process children first
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        // Aggregate sum and count for the current subtree
        int currentSum = left.first + right.first + root->val;
        int currentCount = left.second + right.second + 1;

        // Check if root value equals subtree integer average
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
```
