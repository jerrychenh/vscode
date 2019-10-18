#include "TreeNode.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        int max, min;
        return isValidBST(root, max, min);
    }

    // root not NULL
    bool isValidBST(TreeNode* root, int& max, int& min) {
        max = root->val;
        min = root->val;
        if(root->left == NULL && root->right == NULL){
            return true;
        }

        if(root->left){
            int leftmin, leftmax;
            if(!isValidBST(root->left, leftmax, leftmin)
                || leftmax >= root->val){
                return false;
            }
            min = leftmin;
        }

        if(root->right){
            int rightmin, rightmax;
            if(!isValidBST(root->right, rightmax, rightmin)
                || rightmin <= root->val){
                return false;
            }
            max = rightmax;
        }

        return true;
    }
};