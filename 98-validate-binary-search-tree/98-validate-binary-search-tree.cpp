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
    bool solve(TreeNode* root, long long min, long long max)
    {
        if(!root)
            return true;
        
        if(root->val >=max || root->val<=min)
            return false;
        
        bool root1 = solve(root->left, min, root->val);
        bool root2 = solve(root->right, root->val, max);
        
        if(root1 && root2)
            return true;
        return false;
      
    }
    bool isValidBST(TreeNode* root) {
        
        bool res = solve(root, LONG_MIN, LONG_MAX);
        return res;
    }
};













































// class Solution {  
//     bool dfs(TreeNode* root, long long mn, long long mx) {
//         if(!root) return true;
        
//         if(root->val <= mn || root->val >= mx) return false;
        
//         bool left = dfs(root->left, mn, root->val);
//         bool right = dfs(root->right, root->val, mx);
        
//         return left && right;
//     }
    
// public:
//     bool isValidBST(TreeNode* root) {
//         return dfs(root, LONG_MIN, LONG_MAX);
//     }
// };