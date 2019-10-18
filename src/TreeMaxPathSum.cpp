#include "TreeNode.h"
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int sum = INT_MIN;
    int maxPathSum(TreeNode* root){
        pathSum(root);
        return sum;
    }

    int pathSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        // left and right is guarantee >= 0
        int left = std::max(0, pathSum(root->left));
        int right = std::max(0, pathSum(root->right));
        sum = std::max(sum, left + right + root->val);

        return std::max(left, right) + root->val;
    }
};