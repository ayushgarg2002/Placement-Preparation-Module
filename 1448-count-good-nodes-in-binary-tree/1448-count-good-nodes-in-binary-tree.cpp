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
    void solve(TreeNode* root, int curr_val, int &cnt)
    {
        if(!root)
            return;
        if(root->val >= curr_val)
        {
            
            cnt++;
            curr_val  = root->val;
            
        }
        
        solve(root->left, curr_val, cnt);
        solve(root->right, curr_val, cnt);
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int cnt=0;
        solve(root,INT_MIN, cnt);
        return cnt;
    }
};