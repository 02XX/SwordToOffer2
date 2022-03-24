#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < int(board.size()); i++)
        {
            for(int j = 0; j < int(board[0].size()); j++)
            {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
    {
        if(i < 0 || i >= int(board.size()) || j < 0 || j >= int(board[0].size()) || board[i][j] != word[k]) return false;
        if(k == int(word.size()) - 1) return true;
        board[i][j] = '\0';
        bool r = (dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1) || dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1));
        board[i][j] = word[k];
        return r;
    }
};

int main()
{
    Solution A;
    string word = "ABCCED";
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    bool a = A.exist(board, word);
    return 0;
}