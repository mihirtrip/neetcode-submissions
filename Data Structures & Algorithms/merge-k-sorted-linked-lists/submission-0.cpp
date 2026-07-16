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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct compare{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };
        priority_queue<ListNode* ,vector<ListNode*>,compare>pq;
        for(auto& a:lists){
            if(a!=nullptr){
                pq.push(a);
            }
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if(node->next!=nullptr){
                pq.push(node->next);
            }
        }
        return ans->next;
    }
};
