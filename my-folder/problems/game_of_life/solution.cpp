class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v(m,vector<int> (n,-1));
        int dx[8] = {0,0,1,1,1,-1,-1,-1};
        int dy[8] = {1,-1,0,1,-1,0,1,-1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int countlive = 0;
                for(int k = 0; k < 8; k++){
                    int nextX = i + dx[k];
                    int nextY = j + dy[k];
                    //cout<<nextX<<" "<<nextY<<endl;
                    if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && board[nextX][nextY] == 1){
                        countlive++;
                    }
                }
                //cout<<i<<"-"<<j<<" "<<countlive<<endl;
                if(board[i][j] == 1){
                    if(countlive == 2 || countlive == 3){
                        v[i][j] = 1;
                    }
                    else
                        v[i][j] = 0;
                }
                else{
                    if(countlive == 3){
                        v[i][j] = 1;
                    }
                    else
                        v[i][j] = 0;
                }
            }
        }
        board = v;
        
        
    }
};