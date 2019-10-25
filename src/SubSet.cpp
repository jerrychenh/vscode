#include <algorithm>
#include <vector>

using namespace std;

class Solution{
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        std::sort(nums.begin(), nums.end());

        addSet(nums, v, 0);
        return res;
    }

    void addSet(vector<int> &nums, vector<int>& v, int pos){
        if(pos == nums.size()){
            res.push_back(v);
            return;
        }

        v.push_back(nums[pos]);
        addSet(nums, v, pos + 1);
        v.pop_back();

        addSet(nums, v, pos + 1);
    }
};