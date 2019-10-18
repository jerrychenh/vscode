#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> count;
    vector<int> ans;
    int num;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        num = N;
        vector<set<int>> connections(N);

        for(auto v : edges){
            connections[v[0]].insert(v[1]);
            connections[v[1]].insert(v[0]);
        }

        for(int i = 0; i < N; ++i){
            count.push_back(1);
            ans.push_back(0);
        }

        dfs(0, -1, connections);
        // now, only the root's (ans[0]) value is correct
        // dfs and comput top down to correct the ans
        dfs1(0, -1, connections);
        return ans;
    }

    // compute num of nodes in  subtree
    // compute num of connections in subtree
    // dfs: compute count/ans bottom up
    void dfs(int subtree, int parent, vector<set<int>>& connections){
        for(auto child : connections[subtree]){
            if(child == parent) continue;

            dfs(child, subtree, connections);
            count[subtree] += count[child];
            ans[subtree] += (ans[child] + count[child]);
        }
    }

    // dfs: compute ans top down
    void dfs1(int subtree, int parent, vector<set<int>>& connections){
        for(auto child : connections[subtree]){
            if(child == parent) continue;

            // comput child connections,
            // (num - count[child]) - count[child] is the num of node diff
            // between child and parent subtree(imagine break the connection between parent/child),
            // you will get two trees with parent/child as root separately
            ans[child] = ans[subtree] + (num - count[child]) - count[child];
            dfs1(child, subtree, connections);
        }
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    vector<int> sd = s.sumOfDistancesInTree(5, edges);
    for(int i : sd){
        cout << i << " " << endl;
    }
    return 0;
}