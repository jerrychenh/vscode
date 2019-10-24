#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, vector<int>>> heap;
        vector<vector<int>> res;

        for(auto v: points){
            heap.push_back(std::make_pair(v[0]*v[0] + v[1]*v[1], v));
        }

        // make heap
        for(int i = 1; i < heap.size(); ++i){
            int pos = i;
            while(pos != 0){
                int parent = (pos - 1)/2;
                if(heap[pos].first < heap[parent].first){
                    std::swap(heap[pos], heap[parent]);
                    pos = parent;
                } else {
                    break;
                }
            }
        }

        for(int i = 0; i < K; ++i){
            std::swap(heap[0], heap[heap.size() - 1]);
            res.push_back(heap.back().second);
            heap.pop_back();

            int pos = 0;
            int len = heap.size();
            while(pos < len){
                int old = pos;
                int right = pos * 2 + 2;
                int left = right - 1;
                if(right < len){
                    // both children valid
                    if(heap[left].first < heap[right].first){
                        if(heap[pos].first > heap[left].first){
                            std::swap(heap[pos], heap[left]);
                            pos = left;
                        }
                    } else {
                        if(heap[pos].first > heap[right].first){
                            std::swap(heap[pos], heap[right]);
                            pos = right;
                        }
                    }
                } else if(left < len){
                    // only left child valid
                    if(heap[pos].first > heap[left].first){
                        std::swap(heap[pos], heap[left]);
                        pos = left;
                    }
                }

                if(old == pos){
                    break;
                }
            }
        }

        return res;
    }
};
// [[-5,4],[-6,-5],[4,6]]
int main(int argc, char** argv){
    Solution s;
    vector<vector<int>> n{{-5,4}, {-6,-5}, {4,6}};
    vector<vector<int>> res = s.kClosest(n, 2);
    for(auto v : res){
        std::cout << v[0] << " " << v[1] << std::endl;
    }
    
}