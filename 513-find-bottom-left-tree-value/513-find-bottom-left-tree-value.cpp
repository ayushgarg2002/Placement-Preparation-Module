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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)
            return -1;
        q.push(root); 
        TreeNode* t;
        while(!q.empty())
        {
            // int sz= q.size();
            t= q.front();
            q.pop();
            if(t->right)
                q.push(t->right);
            if(t->left)
                q.push(t->left);
            
                                  
        }
        return t->val;
    }
};