#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }

        radixSort(nums);
        int maxGap = 0;
        for(int i = 1; i < nums.size(); ++i){
            maxGap = std::max(maxGap, nums[i] - nums[i-1]);
        }

        return maxGap;
    }

    void radixSort(vector<int>& nums) {
        if(nums.size() < 2){
            return;
        }

        int max = *std::max_element(nums.begin(), nums.end());
        int divide = 1;
        vector<int> aux(nums.size());
        while(max/divide > 0){
            vector<int> count(10);
            for(int i = 0; i < nums.size(); ++i){
                count[(nums[i]/divide) % 10]++;
            }

            for(int i = 1; i < count.size(); ++i){
                count[i] += count[i - 1];
            }

            for(int i = nums.size() - 1; i >= 0; --i){
                aux[--count[(nums[i]/divide) % 10]] = nums[i];
            }

            nums = aux;
            divide *= 10;
        }
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> num{2,6,9,0,3};
    s.maximumGap(num);
    return 0;
}