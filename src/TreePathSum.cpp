#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }

        return subPathSum(root, sum);
    }

    bool subPathSum(TreeNode* root, int sum) {
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val) return true;
        }
        
        return (root->left ? subPathSum(root->left, sum - root->val) : false)
                || (root->right ? subPathSum(root->right, sum - root->val) : false);
    }
// ############### Path sum II, return sum path ###############
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root != NULL){
            subPathSum(root, sum, vector<int>());
        }

        return res;
    }

    bool subPathSum(TreeNode * root, int sum, vector<int> path){
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                path.push_back(root->val);
                res.push_back(path);
                return;
            }
        }

        path.push_back(root->val);
        if(root->left != NULL){
            subPathSum(root->left, sum - root->val, path);
        }

        if(root->right != NULL){
            subPathSum(root->right, sum - root->val, path);
        }
    }
};