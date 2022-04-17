/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Thanks to rachit jain and Gaurav Sen
        //https://www.youtube.com/watch?v=xbpUHSKoALg
        
        Node* first = head;
        Node* second = head;
        while(first != NULL){
            second = first -> next;
            Node* middleNode = new Node(first -> val);
            first -> next = middleNode;
            middleNode -> next = second;
            first = second;
        }
        
        first = head;
        while(first != NULL){
            if(first -> random != NULL){
                first -> next -> random = first -> random -> next;
            }
            first = first -> next -> next;
        }
        
        first = head;
        second = head;
        Node* copyList = new Node(0);
        Node* node = copyList;
        while(first != NULL){
            second = first -> next -> next;
            node -> next = first -> next;
            first -> next = second;
            first = first -> next;
            node = node -> next;
        }
        return copyList -> next;
        
    }
};





