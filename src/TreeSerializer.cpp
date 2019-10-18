#include "TreeNode.h"
#include <string>
#include <list>
#include <iostream>
#include <vector>

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
        if(data.compare("[]") == 0) return NULL;

        list<TreeNode*> trees;
        TreeNode * root = NULL;
        data = data.substr(1, data.size() - 2);

        // split by ',' to vector
        vector<string> nodes;
        size_t start = 0;
        size_t end = data.find(",");
        while(end != string::npos){
            string token = data.substr(start, end - start);
            nodes.push_back(token);
            start = end + 1;
            end = data.find(",", start);
        }
        nodes.push_back(data.substr(start));

        // reconstruct tree
        root = new TreeNode(stoi(nodes[0]));
        trees.push_back(root);
        for(int i = 1; i < nodes.size(); i+=2){
            TreeNode* node = trees.front();
            if(nodes[i].compare("null") == 0){
                node->left = NULL;
            } else {
                node->left = new TreeNode(stoi(nodes[i]));
                trees.push_back(node->left);
            }

            if(i + 1 < nodes.size()){
                if(nodes[i + 1].compare("null") == 0){
                    node->right = NULL;
                } else {
                    node->right = new TreeNode(stoi(nodes[i + 1]));
                    trees.push_back(node->right);
                }
            }

            trees.pop_front();
        }

        return root;
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
    // cout << codec.serialize(&t1) << endl;
    codec.deserialize(codec.serialize(&t1));
    return 0;
}