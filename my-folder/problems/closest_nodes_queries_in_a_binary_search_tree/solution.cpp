/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v){
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inorder(root, v);
        int n = queries.size();
        vector<vector<int>> ans(n,vector<int>(2,-1));
        for(int i=0; i < queries.size(); i++){
            int x = queries[i];
            if(v[0] > x){
                ans[i][0] = -1;
                
            }
            else{
                int l = 0;
                int r = v.size() - 1;
                int mid;
                int f = 0;
                int ind = 0;
                while(l <= r){
                    mid = l + (r-l)/2;
                    if(v[mid] == x){
                        f=1;
                        ans[i][0]=x;
                        break;
                    }
                    else if(v[mid] > x){
                        r = mid-1;
                    }
                    else{
                        ind = mid;
                        l = mid + 1;
                    }
                        
                }
                if(f == 0)
                    ans[i][0] = v[ind];
            }
            if(v[v.size() - 1] < x){
                ans[i][1]=-1;
            }
            else{
                int l = 0;
                int r = v.size()-1;
                int mid;
                int f=0;
                int ind=0;
                while(l <= r){
                    mid = l+(r-l)/2;
                    if(v[mid] == x){
                        f = 1;
                        ans[i][1]=x;
                        break;
                    }
                    else if(v[mid]>x){
                        ind = mid;
                        r = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                        
                }
                if(f == 0)
                    ans[i][1]=v[ind];
            }
        }
        return ans;
    }
};

