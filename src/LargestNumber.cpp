#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

// Given a list of non negative integers, arrange them such that they form the largest number.

// Example 1:

// Input: [10,2]
// Output: "210"
// Example 2:

// Input: [3,30,34,5,9]
// Output: "9534330"
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto func = [](const int& an, const int& bn){
            string as = std::to_string(an);
            string bs = std::to_string(bn);
            string tmp = as;
            as = as + bs;
            bs = bs + tmp;

            for(int i = 0; i < as.length(); ++i){
                char ai = as[i];
                char bi = bs[i];
                if(ai == bi) continue;
                if(ai < bi){
                    return true;
                } else {
                    return false;
                }

            }

            return false;
        };

        std::sort(nums.rbegin(), nums.rend(), func);
        string res;
        for(int n : nums){
            res += std::to_string(n);
        }

        if(res[0] == '0'){
            return "0";
        }

        return res;
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> num{1,6,2,343,34,5};
    std::cout << s.largestNumber(num) << std::endl;
}