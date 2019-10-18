#include "TreeNode.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;

        return isUnivalTree(root->left, root->val)
                && isUnivalTree(root->right, root->val);
    }

    bool isUnivalTree(TreeNode* root, int val) {
        if(root == NULL) return true;

        if(root->val != val) return false;
        return isUnivalTree(root->left, val)
            && isUnivalTree(root->right, val);
    }
};