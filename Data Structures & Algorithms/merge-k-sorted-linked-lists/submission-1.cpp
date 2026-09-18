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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* curr = NULL;
        ListNode* head = NULL;
        while(a && b){
            if(a->val <= b->val){
                if(!head){
                    head = a;
                    curr = a;
                } else {
                    curr->next = a;
                    curr = curr->next;
                }
                a = a->next;
            } else {
                if(!head){
                    head = b;
                    curr = b;
                } else {
                    curr->next = b;
                    curr = curr->next;
                }
                b = b->next;
            }
        }

        if(!head){
            head = a ? a : b;
            curr = a ? a : b;
        } else {
            curr->next = a ? a : b;
            curr = curr->next;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if(l == r){
            return lists[l];
        }
        int mid = l + (r-l)/2;
        ListNode* a = mergeKLists(lists, l, mid);
        ListNode* b = mergeKLists(lists, mid+1, r);
        return merge(a, b);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        return mergeKLists(lists, 0, lists.size()-1);
    }
};
