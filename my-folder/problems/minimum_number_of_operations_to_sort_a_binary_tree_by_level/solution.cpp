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
    int minSwaps(vector<int>& v){
        int n = v.size();
        map<int, int> map;
        for (int i = 0; i < n; i++)
            map[v[i]] = i;

        sort(v.begin(), v.end());

        vector<bool> visited(n, 0);


        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || map[v[i]] == i)
                continue;

            int j = i, cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = map[v[j]];
                cycle_size++;
            }
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front -> left != NULL){
                    q.push(front -> left);
                }
                if(front -> right != NULL){
                    q.push(front -> right);
                }
            }
            count += minSwaps(v);
        }
        return count;
    }
};