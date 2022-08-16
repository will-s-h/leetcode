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
    TreeNode* f;
    int l; int h;
    
    void dfs(TreeNode* child, TreeNode* parent){
        if(child->val < l){
            parent->left = child->right;
            if(child->right != nullptr) dfs(child->right, parent);
        } else if(child->val > h){
            parent->right = child->left;
            if(child->left != nullptr) dfs(child->left,parent);
        }
        if(child->left != nullptr) dfs(child->left, child);
        if(child->right != nullptr) dfs(child->right, child);
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        l = low; h = high;
        while(root != nullptr && (root->val > high || root->val < low)){
            if(root->val > h) root = root->left;
            else root = root->right;
        }
        TreeNode* f = root;
        if(root == nullptr) return f;
        if(root->left != nullptr) dfs(root->left, root);
        if(root->right != nullptr) dfs(root->right, root);
        return f;
    }
};
