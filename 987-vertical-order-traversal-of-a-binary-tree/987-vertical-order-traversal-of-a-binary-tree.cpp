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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
	if (!root) return {};
	map<int, vector<int>> m;
	vector<pair<TreeNode*, int>> q {{root, 0}}, tmp;
	while (!q.empty()) {
		int sz = q.size();
		for (int i=0; i<sz; i++) {
			auto p = q[i];
			m[p.second].push_back(p.first->val);
			if (p.first->left) tmp.emplace_back(p.first->left, p.second - 1);
			if (p.first->right) tmp.emplace_back(p.first->right, p.second + 1);
		}
		sort(tmp.begin(), tmp.end(), [](const auto& a, const auto& b){
			return a.second == b.second ? a.first->val < b.first->val : a.second < b.second;
		});
		tmp.swap(q);
		tmp.clear();
	}
	vector<vector<int>> ans;
	for (auto& p : m) {
		ans.push_back(move(p.second));   
	}
	return ans;
}
};