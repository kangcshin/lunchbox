/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) return true;
        if(t == NULL) return true;
        if(s == NULL) return false;
        
        return (traversal(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t));
    }
    
    bool traversal(TreeNode*s, TreeNode*t){
        if(s == NULL && t == NULL) return true;
        if(t == NULL || s == NULL) return false;
        
        if(s->val != t->val) return false;
        return (traversal(s->left,t->left) && traversal(s->right,t->right));
    }
};