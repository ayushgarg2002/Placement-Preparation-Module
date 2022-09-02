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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vec;
        double sum=0;
        if(!root)
            return vec;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int t = q.size();
            int k = t;
            while(t--)
            {
                TreeNode* td = q.front();
                q.pop();
                sum += td->val;
                if(td->left)
                {
                    q.push(td->left);
                    
                }
                if(td->right)
                {
                    q.push(td->right);
                    
                }
            }
            double val = (double)sum/(double)k;
           
            vec.push_back(val);
            sum=0;
            
        }
        return vec;
    }
};