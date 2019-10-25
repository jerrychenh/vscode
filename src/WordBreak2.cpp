#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    map<int, vector<string>> mapAtPos;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        appendWord(s, s.length() - 1, wordDict);
        return mapAtPos[0];
    }

    // not pass, memory/time limit exceed
    void appendWord(string& s, int pos, vector<string>& wordDict){
        if(pos < 0) return;

        vector<string> res;
        for(string& word : wordDict){
            if(s.compare(pos, word.length(), word) == 0){
                int nxtPos = pos + word.length();
                if(nxtPos == s.length()){
                    res.push_back(word);
                }

                for(string& sub : mapAtPos[nxtPos]){
                    res.push_back(word + " " + sub);
                }
            }
        }

        mapAtPos[pos] = res;
        appendWord(s, pos - 1, wordDict);
    }
};

int main(int argc, char** argv){
    Solution s;
    // string str = "pineapplepenapple";
    // vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};

    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaa";
    vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    vector<string> res = s.wordBreak(str, wordDict);
    // for(string& s: res){
    //     std::cout << s << std::endl;
    // }

    std::cout << res.size() << std::endl;
    return 0;
}