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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> vec;
        if(!root)
            return vec;
        vector<int>v;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int t= q.size();
            while(t--)
            {
                TreeNode* td = q.front();
                q.pop();
                v.push_back(td->val);
                if(td->left)
                {
                    q.push(td->left);
                }
                if(td->right)
                {
                    q.push(td->right);
                }
            }
            vec.push_back(v);
            v.clear();
            
        }
        return vec;
    }
};