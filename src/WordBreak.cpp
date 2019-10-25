#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:

// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
// Example 2:

// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []

// dynamic programming, left to right
// a good practice of large problem to small problem vs. small to large,
// but to this problem small to right doesn't work, too many sub solutions
// see following comment and WordBreak2.cpp
class Solution {
public:
    map<int, vector<string>> mapAtPos;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0){
            return vector<string>();
        }

        appendWord(s, 0, wordDict);
        return mapAtPos[0];
    }

    // current substring(at pos) solution depends on solution to the right of the pos index
    // so if there's no solution to sub-substring, no solution to current substring: 
    // mapAtPos[nxtPos] empty -> mapAtPos[pos] empty, also no need to check pos that is > nxtPos
    // compare this to dp that from right to left, example:
    // string str = "aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    // notice there's 'b' in str, so no solution obviously, if use right to left dp:
    // substring right of 'b':aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa,  will have part solution
    // storing many many partial solutions at mapAtPos['> index of b'], which is useless
    // If using left to right dp, mapAtPos['index of b'] will always has no solution(empty vector),
    // Recursion will stop at index 'b', also resluting in all empty in mapAtPos befor 'b'
    void appendWord(string& s, int pos, vector<string>& wordDict){
        if(mapAtPos.find(pos) != mapAtPos.end() || pos == s.length()){
            return;
        }

        vector<string> tmp;
        for(string& word : wordDict){
            if(s.compare(pos, word.length(), word) == 0){
                int nxtPos = pos + word.length();
                appendWord(s, nxtPos, wordDict);
                if(nxtPos == s.length()){
                    tmp.push_back(word);
                }
                // else
                for(string& str: mapAtPos[nxtPos]){
                    tmp.push_back(word + " " + str);
                }
            }
        }

        mapAtPos[pos] = tmp;
    }
};

int main(int argc, char** argv){
    Solution s;
    string str = "pineapplepenapple";
    vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};

    // string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaa";
    // vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    vector<string> res = s.wordBreak(str, wordDict);
    for(string& s: res){
        std::cout << s << std::endl;
    }

    std::cout << res.size() << std::endl;
    return 0;
}