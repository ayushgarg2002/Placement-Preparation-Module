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
        vector<int> ans;
        if(!root)
            return vec;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty())
        {
            
            int t  = q.size(); 
            vec.push_back(ans);
            ans.clear();
            while(t--){
           auto td = q.front();
            q.pop();
            if(td->left){
                q.push(td->left);
                ans.push_back(td->left->val);
            }
            if(td->right){
                q.push(td->right);
                ans.push_back(td->right->val);
            }
                
        }
                
        }
        return vec;
    }
};