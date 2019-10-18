#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> distances(N, vector<int>(N, 0));
        vector<int> sumDist(N, 0);

        for(vector<int> edge: edges){
            distances[edge[0]][edge[1]] = 1;
            distances[edge[1]][edge[0]] = 1;
        }

        vector<int> level;
        vector<int> nxt_level;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(distances[i][j] != 0){
                    level.push_back(j);
                }
            }

            while(!level.empty()){
                int tmp = level.back();
                level.pop_back();
                for(int k = 0; k < N; ++k){
                    if(k == i) continue;
                    if(distances[tmp][k] != 0){
                        int d = distances[i][tmp] + distances[tmp][k];
                        if(distances[i][k] > 0){
                            if(d < distances[i][k]){
                                nxt_level.push_back(k);
                                distances[i][k] = d;
                                distances[k][i] = d;
                            }
                        } else {
                            nxt_level.push_back(k);
                            distances[i][k] = d;
                            distances[k][i] = d;
                        }
                    }
                }

                if(level.empty() && !nxt_level.empty()){
                    level = nxt_level;
                    nxt_level.clear();
                }
            }
        }

        for(int i = 0; i < N; ++i){
            sumDist[i] = std::accumulate(distances[i].begin(), distances[i].end(), 0);
        }

        return sumDist;
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