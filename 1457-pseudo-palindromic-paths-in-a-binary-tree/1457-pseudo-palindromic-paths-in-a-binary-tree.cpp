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
    int cnt=0;
    //vector<int>vec(10, 0);
    int vec[10]={0};
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        vec[root->val]++;
        if(root->left== NULL && root->right==NULL)
        {
            int val=0;
            for(int i=0; i<=9; i++)
            {
                if(vec[i] %2 !=0)
                    val++;
            }
            
            if(val <=1)
                cnt++;
        }
        solve(root->left);
        solve(root->right);
        
        vec[root->val]--;
        
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        solve(root);
        return cnt;
    }
};