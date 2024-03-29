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
//     bool solve(TreeNode* root, int k, int &sum) {
        
//         if(!root)
//             return false;
//         sum+=root->val;
//         if(sum == k)
//             return true;
//         root = root->left;
//         root = root->right;
        
//         sum-= root->val;
        
        
//         return false;
//     }
//     bool findTarget(TreeNode* root, int k) {
//            return solve(root, k, root->val);
//     }
    // map<int,int>m;
   vector<int> vec;
    bool findTarget(TreeNode* root, int k) {
       pre(root);
        // for(auto p: m){
        //     int x=p.first;
        //     m[x]--;
        //     if(m.find(k-x)!=m.end()  && m[k-x] > 0)return true;
        // }
        sort(vec.begin(), vec.end());
        int i=0, j=vec.size()-1;
        for(i=0, j=j; i<j; i,j)
        {
            if(vec[i] + vec[j] == k)
                return true;
            else if(vec[i] +  vec[j] >k)
                j--;
            else
                i++;
        }
            
        return false;
    }
    void pre(TreeNode* root){
        if(!root)return;
        // m[root->val]++;
        vec.push_back(root->val);
        pre(root->left);
        pre(root->right);
        
    }
};