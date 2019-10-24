#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void bubble(vector<int>& num){
        for(int i = num.size() - 2; i >= 0; --i){
            for(int j = 0; j <= i; ++j){
                if(num[j] > num[j+1]){
                    std::swap(num[j], num[j+1]);
                }
            }
        }
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<int> n{3,2,0,1};
    s.bubble(n);
    for(int i : n){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}