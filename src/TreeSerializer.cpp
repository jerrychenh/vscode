#include "TreeNode.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "[]";

        list<TreeNode*> level;
        list<TreeNode*> nxt_level;
        list<TreeNode*> seq;

        level.push_back(root);
        while(!level.empty()){

            bool allNull = true;
            while(!level.empty()){
                TreeNode* tmp = level.front();
                level.pop_front();
                seq.push_back(tmp);
                if(tmp){
                    allNull = false;
                    nxt_level.push_back(tmp->left);
                    nxt_level.push_back(tmp->right);
                }
            }

            if(allNull){
                break;
            }

            if(!nxt_level.empty()){
                level = nxt_level;
                nxt_level.clear();
            }
        }

        // pop any null in the tail
        while(seq.back() == NULL){
            seq.pop_back();
        }

        string s = "[";
        int i = 0;
        for(TreeNode* t : seq){
            if(i) s += ",";
            if(t == NULL){
                s += "null";
            }
            else
            {
                s += to_string(t->val);
            }
            ++i;
        }

        s += "]";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char** argv){
    Codec codec;
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t3;
    t3.right = &t2;
    cout << codec.serialize(&t1) << endl;

    return 0;
}