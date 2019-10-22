#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xNum = 0;
        int oNum = 0;

        for(int i = 0; i < 3; ++i){
            string row = board[i];
            for(int j = 0; j < 3; ++j){
                if(row[j] == 'O'){
                    oNum++;
                }
                else if(row[j] == 'X'){
                    xNum++;
                }
            }
        }

        if(xNum < oNum || xNum - 1 > oNum){
            return false;
        }

        if(xNum == oNum && xNum >= 3){
            // X not success
            if(isSuccess(board, 'X'))
                return false;
        }
        else if(xNum == oNum + 1 && oNum >= 3) {
            // O not success
            if(isSuccess(board, 'O'))
                return false;
        }

        return true;
    }

    bool isSuccess(vector<string>& board, char ch){
        for(int i = 0; i < 3; i++){
            if(board[i][0] == ch 
                && board[i][1] == ch
                && board[i][2] == ch)
                return true;

            if(board[0][i] == ch 
                && board[1][i] == ch
                && board[2][i] == ch)
                return true;
        }

        if(board[0][0] == ch 
            && board[1][1] == ch
            && board[2][2] == ch)
            return true;

        if(board[0][2] == ch 
            && board[1][1] == ch
            && board[2][0] == ch)
            return true;

        return false;
    }
};

int main(int argc, char** argv){
    vector<string> board{"XOX","O O","XOX"};
    Solution s;
    s.validTicTacToe(board);
    return 0;
}