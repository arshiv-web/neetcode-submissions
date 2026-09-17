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
        if(!head) return head;
        unordered_map<Node*, Node*> mp;
        Node * newHead = new Node(head->val);
        mp[head] = newHead;
        Node * temp = head;
        Node * temp1 = newHead;

        while(temp->next) {
            temp = temp->next;
            Node * nn = new Node(temp->val);
            mp[temp] = nn;
            temp1->next = nn;
            temp1 = nn;
        }

        temp = head;
        temp1 = newHead;

        while(temp && temp1) {
            temp1->random = mp[temp->random];
            temp = temp->next;
            temp1 = temp1->next;
        }
        return newHead;
    }

};
