/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if(root == NULL) {
            return v;
        }
        stack<TreeNode *> s;
        stack<bool> t;
        s.push(root);
        t.push(true);
        TreeNode *cur;
        while(!s.empty()) {
            cur = s.top();
            if(!t.top()) {
                s.pop();
                t.pop();
                v.push_back(cur->val);
                continue;
            }
            t.pop();
            t.push(false);
            if(cur->right != NULL) {
                s.push(cur->right);
                t.push(true);
            }
            if(cur->left != NULL) {
                s.push(cur->left);
                t.push(true);
            }
        }
        return v;
    }
};
