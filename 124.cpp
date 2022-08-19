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
    int val;
    
    int dfs(TreeNode* n){
        if(n == nullptr) return 0;
        int l = dfs(n->left);
        int r = dfs(n->right);
        val = max(val, max(max(n->val, n->val + l + r), max(n->val + l, n->val + r)));
        return max(n->val, max(n->val + l, n->val + r));
    }
    
    int maxPathSum(TreeNode* root) { //O(n)
        val = INT_MIN;
        dfs(root);
        return val;
    }
};
