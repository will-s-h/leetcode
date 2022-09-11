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
public:
    int sum;
    
    void dfs(TreeNode* t, bool isLeft){
        if(t == nullptr) return;
        if(isLeft && t->left == nullptr && t->right == nullptr){
            sum += t->val;
            return;
        }
        dfs(t->left, true);
        dfs(t->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) { //O(N)
        sum = 0;
        dfs(root, false);
        return sum;
    }
};
