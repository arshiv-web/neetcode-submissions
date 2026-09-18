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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevGroup = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr;
            for(int i = 1; i < k && temp; i++){
                temp = temp->next;
            }

            if(!temp) {
                break;
            }

            ListNode* nextGroup = temp->next;
            temp->next = NULL;

            ListNode* rev = reverse(curr);

            if(prevGroup){
                prevGroup->next = rev;
            } else {
                head = rev;
            }


            curr->next = nextGroup;

            prevGroup = curr;
            curr = curr->next;
        }
        return head;
    }
};
