class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int recta = (ax2-ax1)*(ay2-ay1);
        int rectb = (bx2-bx1)*(by2-by1);
        if( ax2 <= bx1 || ax1 >= bx2 || ay1 >= by2 || ay2 <= by1)
            return recta + rectb;
        vector<int> a{ax1, ax2, bx1, bx2};
        vector<int> tempa = a;
        vector<int> b{ay1, ay2, by1, by2};
        vector<int> tempb = b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int overlap = (a[2]-a[1])*(b[2]-b[1]);
        return recta + rectb - overlap;
    }
};

