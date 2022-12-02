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
    int deepestLeavesSum(TreeNode* root) {

        stack<pair<TreeNode *, int>> nodes;
        nodes.push(make_pair(root, 0));
        unordered_map<int, int> dict;
        
        int sum = 0, deep = 0;
        while (!nodes.empty()) {
            root = nodes.top().first;
            int val = nodes.top().second;
            nodes.pop();
            
            if (root->left)
                nodes.push(make_pair(root->left, val + 1));
            
            if (root->right)
                nodes.push(make_pair(root->right, val + 1));
            
            dict[val] += root->val;
            
            if (val > deep) {
                deep = val;
            }
            
        }
                   
        return dict[deep];
    }
};
