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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q; 
        vector<int>vec;
        if(!root)
            return vec;
       
        q.push(root);
        while(!q.empty())
        {
           int sz= q.size();
            TreeNode* t;
            while(sz--)
            {
                t = q.front();
                q.pop();
                
                if(t->left) 
                   q.push(t->left);
                if(t->right) 
                   q.push(t->right);
            }
            vec.push_back(t->val);
        }
        return vec;
    }
};