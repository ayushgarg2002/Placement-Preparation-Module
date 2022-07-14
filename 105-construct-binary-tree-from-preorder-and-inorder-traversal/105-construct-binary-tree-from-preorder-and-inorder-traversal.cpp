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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preStart, int inStart, int inEnd, int n, map<int, int> &mapi)
    {
      
        if(preStart>=n || inStart>inEnd)
            return NULL;
        
        int ind = preorder[preStart++];
        int partition  = mapi[ind];
        
        TreeNode* root = new TreeNode(ind);
        root->left= solve(preorder, inorder, preStart, inStart, partition-1, n , mapi);
        root->right= solve(preorder, inorder, preStart, partition+1, inEnd, n, mapi) ;
        
        return root;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart=0;
        int n= inorder.size();
        map<int , int> mapi;
        for(int i=0; i<n;i++)
        {
            mapi[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, inorder, preStart, 0, n-1, n, mapi )  ;
        return root;
    }
};