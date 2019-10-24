#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void quickSort(vector<int>& nums){
        quickSort(nums, 0, nums.size() - 1);
    }

    void quickSort(vector<int>& nums, int start, int end){
        if(start >= end) return;

        int pivot = nums[start];
        int i = start, j = end;
        
        // loop invariant: 
        // i point to pivot, nums[k] < pivot for k < i; nums[k] >= pivot for k > j
        // when stop, i == j
        while(i < j){
            while(i < j && nums[j] >= pivot){
                --j;
            }

            if(i < j){
                nums[i] = nums[j];
            }

            while(i < j && nums[i] < pivot){
                ++i;
            }

            if(i < j){
                nums[j] = nums[i];
            }
        }
        nums[i] = pivot;
        quickSort(nums, start, i - 1);
        quickSort(nums, i + 1, end);
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> n{2,4,5,7,3,9,1,0,11};
    s.quickSort(n);
    for(int i:n){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}