#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;

        stack<TreeNode*> nodes;
        // left:0, righ:1, self:2
        stack<int> status;

        nodes.push(root);
        status.push(0);

        while(!nodes.empty()){
            int st = status.top();
            status.pop();
            TreeNode* cur = nodes.top();
            if(!cur){
                nodes.pop();
                continue;
            }

            switch(st){
                case 0:
                    status.push(1);
                    status.push(0);
                    nodes.push(cur->left);
                    break;
                case 1:
                    status.push(2);
                    status.push(0);
                    nodes.push(cur->right);
                    break;
                case 2:
                    nodes.pop();
                    res.push_back(cur->val);
                    break;
                default:
                    break;
            }
        }

        return res;
    }
};