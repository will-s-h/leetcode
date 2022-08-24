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
    struct data{int sum, n, m;}; //sum, number of total nodes, number of nodes = average
    
    data averageAndNum(TreeNode *root){
        if(root == nullptr) return {0,0,0};
        if(root->left == nullptr && root->right == nullptr) return {root->val,1,1};
        data l = averageAndNum(root->left);
        data r = averageAndNum(root->right);
        bool isRoot = ((l.sum+r.sum+root->val)/(l.n+r.n+1) == root->val);
        return {l.sum+r.sum+root->val, l.n+r.n+1, l.m+r.m+isRoot};
    }
    
    int averageOfSubtree(TreeNode* root) { //O(N)
        return averageAndNum(root).m;
    }
};
