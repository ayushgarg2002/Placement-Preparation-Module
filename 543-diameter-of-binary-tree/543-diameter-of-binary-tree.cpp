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
    int mx =INT_MIN;
        int solve(TreeNode* root)
    {
         if(!root)
        return 0;
        
        int x = solve(root->left);
        int y = solve(root->right);
         mx = max(mx , x+ y );
        return (max(x, y)+1);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // int  mx =INT_MIN;
      int x =  solve(root);
        
        return mx;
         
    }
};