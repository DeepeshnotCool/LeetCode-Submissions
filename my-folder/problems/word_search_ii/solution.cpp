class Solution {
public:
    struct TrieNode{
        bool is_end;
        string word;
        TrieNode* child[26];

        TrieNode(){
            is_end = false;
            word = "";
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string& s){
        int n = s.size();
        TrieNode* curr = root;

        for(int i = 0; i < n; i++){
            int index = s[i] - 'a';

            if(curr -> child[index] == NULL){
                curr -> child[index] = new TrieNode();
            }
            curr = curr -> child[index];
        }
        curr -> is_end = true;
        curr -> word = s;
    }

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m, TrieNode* curr, vector<string>& v){    
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '0'){
            return;
        }

        int index = board[i][j] - 'a';

        if(curr -> child[index] == NULL){
            return;
        }
        curr = curr -> child[index];
        if(curr -> is_end){
            v.push_back(curr -> word);
            curr -> is_end = false;
        }

        char ch = board[i][j];

        board[i][j] = '0';
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++){
            int nexti = i + dx[k];
            int nextj = j + dy[k];
            dfs(board, nexti, nextj, n, m, curr, v);
        }
        
        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int n = board.size();
        int m = board[0].size();

        for(auto it: words){
            insert(it);
        }
        vector<string> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(board, i, j, n, m, root, v);
            }
        }

        return v;
    }
};