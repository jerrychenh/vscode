#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heapSort(vector<int>& nums){
        if(nums.size() < 2) return;

        makeHeap(nums);
        for(int i = nums.size() - 1; i > 0; --i){
            rearrange(nums, i);
        }
    }

    void rearrange(vector<int>& nums, const int pos){
        std::swap(nums[0], nums[pos]);
        int index = 0;
        while(index < pos){
            int old = index;
            int right = index * 2 + 2;
            int left = right - 1;
            if(right < pos){
                if(nums[left] < nums[right]){
                    if(nums[index] > nums[left]){
                        std::swap(nums[index], nums[left]);
                        index = left;
                    }
                } else {
                    if(nums[index] > nums[right]){
                        std::swap(nums[index], nums[right]);
                        index = right;
                    }
                }
            } else if(left < pos){
                 if(nums[index] > nums[left]){
                    std::swap(nums[index], nums[left]);
                    index = left;
                }
            } 

            if(old == index){
                break;
            }
        }
    }

    void makeHeap(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i){
            bottomUp(nums, i);
        }
    }

    void bottomUp(vector<int>& nums, int pos){
        while(pos != 0){
            int parent = (pos - 1) / 2;
            if(nums[pos] < nums[parent]){
                std::swap(nums[pos], nums[parent]);
                pos = parent;
            } else {
                break;
            }
        }
    }
};

int main(int argc, char** argv){
    vector<int> n{3,6,7,9,1,0};
    Solution s;
    s.heapSort(n);

    for(int i : n){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}