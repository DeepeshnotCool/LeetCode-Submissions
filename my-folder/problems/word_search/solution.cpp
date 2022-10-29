class Solution {
public:

    bool helper(int i, int j, int n, int m, string word, vector<vector<char>>& board, int index){
        if(index >= word.size())
            return true;
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]){
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '0';
        bool left = helper(i-1, j, n, m, word, board, index + 1);
        bool top = helper(i, j+1, n, m, word, board, index + 1);
        bool right = helper(i+1, j, n, m, word, board, index + 1);
        bool bottom = helper(i, j-1, n, m, word, board, index + 1);
        board[i][j] = ch;
        return left || top || right || bottom;
    }



    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(helper(i, j, n, m, word, board, 0))
                    return true;
            }
        }
        return false;
    }
};