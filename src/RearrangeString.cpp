#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        if(S.length() < 2) return S;

        string res(S.length(), ' ');
        map<char, int> m;
        for(char c: S){
            if(m.find(c) != m.end()){
                m[c]++;
            }
            else{
                m[c] = 1;
            }
        }

        vector<pair<char, int>> chars(m.begin(), m.end());
        std::sort(chars.begin(), chars.end(), 
                [](const pair<char, int>& p1, const pair<char, int>& p2){return p2.second < p1.second;});

        int count = 0;
        int idx = 0;
        for(auto p : chars){
            for(int i = 0; i < p.second; ++i){
                ++count;
                res[idx] = p.first;
                if(i == p.second - 1){
                    idx = (idx + 1) % S.length();
                }
                else{
                    idx = (idx + 2) % S.length();
                }

                if(count == S.length()) break;
                while(res[idx] != ' '){
                    idx = (idx + 1) % S.length();
                }
            }
        }

        for(int i = 1; i < S.length(); ++i){
            if(res[i] == res[i-1]) return "";
        }
        return res;
    }
};

int main(int argc, char** argv){
    Solution s;
    std::cout << s.reorganizeString("aaaabbbb");
    return 0;
}