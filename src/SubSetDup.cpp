#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        std::sort(nums.begin(), nums.end());
        addSet(nums, v, 0);
        return res;
    }

    void addSet(vector<int>& nums, vector<int>& v, int pos){
        if(pos == nums.size()){
            res.push_back(v);
            return;
        }

        v.push_back(nums[pos]);
        addSet(nums, v, pos + 1);
        v.pop_back();

        ++pos;
        while(pos < nums.size()){
            if(nums[pos] == nums[pos - 1]){
                ++pos;
            }
            else{
                break;
            }
        }
        addSet(nums, v, pos);
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> n{1,2,3};
    auto res = s.subsetsWithDup(n);

    return 0;
}