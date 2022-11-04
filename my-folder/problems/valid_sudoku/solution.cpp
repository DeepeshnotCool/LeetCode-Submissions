class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, int> m1st, m2nd, m3rd;
        for(int i = 0; i < 9; i++){
            map<int, int> mRow, mCol;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int x = int(board[i][j]) - '0';
                    mRow[x]++;
                }
                if(board[j][i] != '.'){
                    int x = int(board[j][i]) - '0';
                    mCol[x]++;
                }

                if(j < 3){
                    if(board[i][j] != '.'){
                        int x = int(board[i][j]) - '0';
                        m1st[x]++;
                    }
                } else if(j < 6){
                    if(board[i][j] != '.'){
                        int x = int(board[i][j]) - '0';
                        m2nd[x]++;
                    }
                } else if(j < 9){
                    if(board[i][j] != '.'){
                        int x = int(board[i][j]) - '0';
                        m3rd[x]++;
                    }
                }
            }

            for(auto it: mRow){
                if(it.second > 1)
                    return false;
            }

            
            for(auto it: mCol){
                if(it.second > 1)
                    return false;
            }

            if(i == 2 || i == 5 || i == 8){
                for(auto it: m1st){
                    if(it.second > 1)
                        return false;
                }
                for(auto it: m2nd){
                    if(it.second > 1)
                        return false;
                }
                for(auto it: m3rd){
                    if(it.second > 1)
                        return false;
                }
                m1st.clear();
                m2nd.clear();
                m3rd.clear();
            }
        }
        return true;
    }
};