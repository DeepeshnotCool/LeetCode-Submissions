class Allocator {
    int v[];
    int ind = -1;
    int len;
    public Allocator(int n) {
        v = new int[n];
        for(int i = 0; i < n; i++){
            v[i] = -1;
        }
        len = n;
    }
    
    public int allocate(int size, int mID) {
        int pos = -1, it = -1, c = 0;
        for(int i = 0; i < len; i++){
            if(v[i] == -1){
                if(c == 0){
                    it = i;
                }
                c++;
            }
            if(c >= size){
                pos = it;
                break;
            }
            else if(v[i] != -1){
                c = 0;
            }
        }
        if(pos == -1){
            return -1;
        }
        for(int i = pos;i < pos + size; i++){
            v[i] = mID;
        }
        return pos;
        
    }
    
    public int free(int mID) {
         int ans=0;
        for(int i=0;i<v.length;i++)
        {
            if(v[i]==mID){
                ans++;
                v[i]=-1;
            }
        }
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.free(mID);
 */