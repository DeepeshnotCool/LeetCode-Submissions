class Solution {
public:
    
    void helper(vector<vector<int>> &image, int sr, int sc, int newcolor, int oldcolor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] == newcolor || image[sr][sc] != oldcolor){
            return;
        }
        
        image[sr][sc] = newcolor;
        helper(image, sr, sc+1, newcolor, oldcolor);
        helper(image, sr, sc-1, newcolor, oldcolor);
        helper(image, sr+1, sc, newcolor, oldcolor);
        helper(image, sr-1, sc, newcolor, oldcolor);
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor = image[sr][sc];
        helper(image, sr, sc, newColor, oldcolor);
        return image;
    }
};