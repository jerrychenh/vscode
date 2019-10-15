#include "TreeNode.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    stack<TreeNode*> stk;
    vector<TreeNode*> inOrderVector;
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }

        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            inOrderVector.push_back(tmp);
            tmp = tmp->right;
            while(tmp){
                stk.push(tmp);
                tmp = tmp->left;
            }
        }

        if(inOrderVector.size() < 2){
            return;
        }

        TreeNode* first = NULL;
        TreeNode* second = NULL;
        for(int i = 0; i < inOrderVector.size(); ++i){
            // only check one side below because of boundary condition: 3, 1, 2
            if(i < inOrderVector.size() - 1 
                && !first
                && inOrderVector[i]->val > inOrderVector[i + 1]->val){
                // 1, 4, 3, 2, 5
                // 5, 2, 3, 4, 1
                // the first unordered is always larger than its neighbour
                // it will run 2 times here, the first one is what we want, 
                // so need to check !first
                first = inOrderVector[i];
            }

            if(i > 0
                && inOrderVector[i]->val < inOrderVector[i - 1]->val){
                // the second unordered is always smaller than its neighbour
                // it may run 1 or 2 times here, the last one is what we want
                second = inOrderVector[i];
            }
        }

        if(first && second){
            int t = first->val;
            first->val = second->val;
            second->val = t;
        }
    }
};

int main(int argc, char** argv){
    Solution s;
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t3;
    t3.right = &t2;

    s.recoverTree(&t1);
    return 0;
}