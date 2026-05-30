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
        int carr = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* nl = new ListNode(0);
        ListNode* curr  = nl;

       
       while(l1 || l2 || carr){
        int sum  = carr;

        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        carr = sum/10;

        curr->next = new ListNode(sum%10);
        curr = curr->next;
       }

       return nl->next;
    }
};
