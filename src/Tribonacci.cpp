#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> arr(n+1, 0);

        return tribonacci(arr, n);
    }

    int tribonacci(vector<int>& arr, int n) {
        if(n < 2) return n;
        if(n == 2) return 1;

        if(arr[n] != 0) return arr[n];
        arr[n] = tribonacci(arr, n-1) + tribonacci(arr, n-2) + tribonacci(arr, n-3);
        return arr[n];
    }
};

int main(int argc, char** argv){
    Solution s;
    std::cout << s.tribonacci(37) << std::endl;
    return 0;
}