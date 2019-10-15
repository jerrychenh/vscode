#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left) return false;
        if(!right) return false;

        if(left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};