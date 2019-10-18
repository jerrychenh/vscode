#include "TreeNode.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<TreeNode*> forest;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::sort(to_delete.begin(), to_delete.end());
        delNodes(root, to_delete, NULL);
        return forest;
    }

    void delNodes(TreeNode* root, vector<int>& to_delete, TreeNode* parent){
        if(root == NULL) return;

        if(shouldDel(root->val, to_delete)){
            if(parent){
                if(parent->left == root){
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            }

            // if cur node should delete, pass NULL
            // note that this way parent still point to child if child not in to_delete
            // Or we can pass an additional flag to mark if parent is deleted
            delNodes(root->left, to_delete, NULL);
            delNodes(root->right, to_delete, NULL);
        } else {
            // if parent is deleted, then push
            if(!parent)
                forest.push_back(root);
            delNodes(root->left, to_delete, root);
            delNodes(root->right, to_delete, root);
        }
    }

    bool shouldDel(int val, vector<int>& to_delete){
        return std::binary_search(to_delete.begin(), to_delete.end(), val);
    }
};