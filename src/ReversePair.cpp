#include <iostream>
#include <vector>

using namespace std;

// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
// You need to return the number of important reverse pairs in the given array.
// Example1:
// Input: [1,3,2,3,1]
// Output: 2

// Example2:
// Input: [2,4,3,5,1]
// Output: 3
// Note:
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.

class Solution {
public:
    // partition and merge
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return partition(nums, 0, nums.size() - 1);
    }

    int partition(vector<int>& nums, int start, int end){
        if(start == end) return 0;

        int mid = (start + end) / 2;
        int count = partition(nums, start, mid) + partition(nums, mid + 1, end);

        // a trick to avoid traversing the right part every time,
        // hopefully it helps meet the time limit with narrow escape:P
        int right = mid + 1;
        for(int left = start; left <= mid; ++left){
            while(right <= end && (long)nums[left] > 2 * (long)nums[right]){
                ++right;
            }
            count += (right - (mid + 1));
        }

        merge(nums, start, mid, end);
        return count;
    }

    void merge(vector<int>& nums, int start, int mid, int end){
        vector<int> tmp;
        int i = start, j = mid + 1;
        while(i <= mid && j <= end){
            // less than, stable sort
            if(nums[i] <= nums[j]){
                tmp.push_back(nums[i]);
                ++i;
            } else {
                tmp.push_back(nums[j]);
                ++j;
            }
        }

        while(i <= mid){
            tmp.push_back(nums[i]);
            ++i;
        }

        while(j <= end){
            tmp.push_back(nums[j]);
            ++j;
        }

        for(int k = 0; k < end - start + 1; ++k){
            nums[start + k] = tmp[k];
        }
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> n{2,4,3,5,1};
    std::cout << s.reversePairs(n) << std::endl;
    
    return 0;
}