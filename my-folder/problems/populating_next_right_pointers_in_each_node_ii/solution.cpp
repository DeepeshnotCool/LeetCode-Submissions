/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                if(i != size -1){
                    auto temp = q.front();
                    front -> next = temp;
                }
                else{
                    front -> next = NULL;
                }
                
                if(front -> left != NULL){
                    q.push(front -> left);
                }
                
                if(front -> right != NULL){
                    q.push(front -> right);
                }
            }
        }
        
        return root;
    }
};