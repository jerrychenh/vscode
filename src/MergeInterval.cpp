#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2)
            return intervals;

        std::sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){return v1[0] <= v2[0];});
        vector<vector<int>> res;

        vector<int> pre;
        for(auto ele : intervals){
            if(pre.size() == 0){
                pre = ele;
                continue;
            }

            if(pre[1] >= ele[1]){
                continue;
            }
            else if(pre[1] >= ele[0]){
                pre[1] = ele[1];
                continue;
            }
            else{
                res.push_back(pre);
                pre = ele;
            }
        }

        res.push_back(pre);
        return res;
    }
};