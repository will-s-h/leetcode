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
    
    unordered_set<int> todel;
    unordered_map<int, TreeNode*> sol; //roots of remaining forest
    
    void dfs(TreeNode* t, TreeNode* parent){ //O(n)
        if(todel.count(t->val) > 0){ //if to delete
            if(sol.count(t->val) > 0){ //if currently a root
                sol.erase(t->val); //remove it from roots
            }
            
            //disconnect parent from child
            if(parent != nullptr && 
               parent->left != nullptr && parent->left->val == t->val) parent->left = nullptr;
            else if(parent != nullptr) parent->right = nullptr;
            
            //add children to roots
            if(t->left != nullptr) sol.insert({t->left->val, t->left});
            if(t->right != nullptr) sol.insert({t->right->val, t->right});
        }
        
        //continue the dfs
        if(t->left != nullptr) dfs(t->left, t);
        if(t->right != nullptr) dfs(t->right, t);
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i : to_delete) todel.insert(i);
        
        sol.insert({root->val, root});
        dfs(root, nullptr);
        
        vector<TreeNode*> ans;
        
        for(int i = 1; i <= 1000; i++){
            if(sol.count(i) > 0){
                ans.push_back(sol[i]);
            }
        }
        
        return ans;
    }
};
