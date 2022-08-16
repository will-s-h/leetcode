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
    vector<int> inOrder;
    
    void dfs(TreeNode* tn){
        if(tn->left != nullptr) dfs(tn->left);
        inOrder.push_back(tn->val);
        if(tn->right != nullptr) dfs(tn->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        
        int l = 0; int r = inOrder.size()-1;
        while(l < r){
            while(l < r && inOrder[l] + inOrder[r] > k){
                r--;
            }
            
            if(l < r && inOrder[l] + inOrder[r] == k) return true;
            
            l++;
        }
        
        return false;
    }
};
