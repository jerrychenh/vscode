#include "TreeNode.h"
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> seq;
    int minDiffInBST(TreeNode* root) {
        // no null check, the problem states there's at least 2 nodes
        inOrderTravel(root);
        int min = INT_MAX;
        for(int i = 1; i < seq.size(); ++i){
            min = std::min(min, seq[i] - seq[i-1]);
        }

        return min;
    }

    void inOrderTravel(TreeNode* root){
        if(root == NULL)
            return;

        inOrderTravel(root->left);
        seq.push_back(root->val);
        inOrderTravel(root->right);
    }
};