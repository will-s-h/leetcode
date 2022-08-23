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
    bool contains(TreeNode* t){
        if(t->left == nullptr && t->right == nullptr) return t->val == 1;
        bool l = false; if(t->left != nullptr) l = contains(t->left);
        bool r = false; if(t->right != nullptr) r = contains(t->right);
        if(!l) t->left = nullptr;
        if(!r) t->right = nullptr;
        return (l || r || t->val == 1);
    }
    
    TreeNode* pruneTree(TreeNode* root) { //O(N)
        if(!contains(root)) return nullptr;
        return root;
    }
};
