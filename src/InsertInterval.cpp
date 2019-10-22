#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isInsert = false;
        for(auto it = intervals.begin(); it < intervals.end(); ++it){
            if(newInterval[0] <= (*it)[0]){
                isInsert = true;
                intervals.insert(it, newInterval);
                break;
            }
        }

        if(intervals.size() == 0 || !isInsert){
            intervals.push_back(newInterval);
        }

        vector<int> pre;
        vector<vector<int>> res;
        for(auto v : intervals){
            if(pre.size() == 0){
                pre = v;
                continue;
            }

            if(pre[1] < v[0]){
                res.push_back(pre);
                pre = v;
                continue;
            } else if(pre[1] < v[1]){
                pre[1] = v[1];
                continue;
            } else {
                continue;
            }
        }

        res.push_back(pre);
        return res;
    }
};