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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) {
            return true;
        }
        TreeNode *p = root->left, *q = root->right;
        if (p == NULL || q == NULL) {
            if(p == NULL && q == NULL) {
                return true;
            }
            else {
                return false;
            }
        }
        stack<TreeNode *> s;
        stack<TreeNode *> t;
        s.push(p);
        t.push(q);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            q = t.top();
            t.pop();
            if(p->val != q->val) {
                return false;
            }
            if(p->right != NULL && q->left != NULL) {
                s.push(p->right);
                t.push(q->left);
            }
            else if (p->right != NULL || q->left != NULL) {
                return false;
            }
            if(p->left != NULL && q->right != NULL) {
                s.push(p->left);
                t.push(q->right);
            }
            else if (p->left != NULL || q->right != NULL) {
                return false;
            }
        }
        return true;
    }
};
