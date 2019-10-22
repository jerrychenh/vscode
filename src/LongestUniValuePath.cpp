#include "TreeNode.h"
#include <algorithm>


class Solution {
public:
    int maxLen = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;

        int left = computeValueLength(root->left, root->val);
        int right = computeValueLength(root->right, root->val);
        maxLen = std::max(left + right, maxLen);
        return maxLen;
    }

    // root: cur subtree to compute length
    // val: root's parent value
    int computeValueLength(TreeNode* root, int val){
        if(root == NULL) return 0;

        int left = computeValueLength(root->left, root->val);
        int right = computeValueLength(root->right, root->val);
        maxLen = std::max(left + right, maxLen);
        if(root->val == val){
            return std::max(left, right) + 1;
        }

        return 0;
    }
};