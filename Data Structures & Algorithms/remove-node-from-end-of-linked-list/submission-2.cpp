/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count{0};
        ListNode* temp{head};
        while(temp){
            count++;
            temp = temp->next;
        }
        int mv{count - n - 1};
        
        if(mv < 0){
            return head = head->next;
        }
        temp = head;
        while(mv && temp){
            temp=temp->next;
            mv--;
        }
        if(temp->next)
            temp->next = temp->next->next;
        return head;
    }
};
