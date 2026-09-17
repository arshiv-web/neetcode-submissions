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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* res = NULL;
        ListNode* t3 = res;
        int carry = 0;

        while(t1 && t2){
            int x = carry + t1->val + t2->val;
            int d = x % 10;
            carry = x / 10;
            if(t3 == NULL){
                ListNode* temp = new ListNode(d);
                res = temp;
                t3 = temp;
            } else {
                t3->next = new ListNode(d);
                t3 = t3->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1){
            int x = carry + t1->val;
            int d = x % 10;
            carry = x / 10;
            if(t3 == NULL){
                ListNode* temp = new ListNode(d);
                res = t3;
                t3 = temp;
            } else {
                t3->next = new ListNode(d);
                t3 = t3->next;
            }
            t1 = t1->next;
        }

        while(t2){
            int x = carry + t2->val;
            int d = x % 10;
            carry = x / 10;
            if(t3 == NULL){
                ListNode* temp = new ListNode(d);
                res = t3;
                t3 = temp;
            } else {
                t3->next = new ListNode(d);
                t3 = t3->next;
            }
            t2 = t2->next;
        }

        while(carry != 0){
            int x = carry;
            int d = x % 10;
            carry = x / 10;
            if(t3 == NULL){
                ListNode* temp = new ListNode(d);
                res = t3;
                t3 = temp;
            } else {
                t3->next = new ListNode(d);
                t3 = t3->next;
            }
        }
        return res;

    }
};
