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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postInd, int inStart, int inEnd, int n, map<int, int>&mapi)
    {
        if(postInd<0 || inStart>inEnd)
            return NULL;
        
        int position = postorder[postInd--];
        int ind = mapi[position];
        TreeNode* root = new TreeNode(position);
        root->right = solve(inorder, postorder, postInd,ind+1 ,inEnd ,n, mapi);
        root->left =  solve(inorder, postorder, postInd, inStart ,ind-1 ,n, mapi);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     int n= postorder.size();
     int postInd = n-1;
     map<int, int> mapi;
        for(int i=0; i<n; i++)
        {
            mapi[inorder[i]] = i;
        }
        TreeNode* root = solve(inorder, postorder, postInd, 0, n-1,n,  mapi);
        return root;
    }
};
// class Solution {
// public:
//     TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postStart, int inStart, int inEnd, int n, map<int, int> &mapi)
//     {
      
//         if(postStart< 0 || inStart>inEnd)
//             return NULL;
        
//         int ind = postorder[postStart--];
//         int partition  = mapi[ind];
        
//         TreeNode* root = new TreeNode(ind);
//         root->right= solve(inorder, postorder, postStart, partition+1, inEnd, n, mapi) ;
//         root->left= solve( inorder,postorder, postStart, inStart, partition-1, n , mapi);
        
        
//         return root;
//     }
        
//       TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//      int n= postorder.size();
//      int postInd = n-1;
//      map<int, int> mapi;
//         for(int i=0; i<n; i++)
//         {
//             mapi[inorder[i]] = i;
//         }
//         TreeNode* root = solve(inorder, postorder, postInd, 0, n-1, n, mapi);
//         return root;
//     }
// };