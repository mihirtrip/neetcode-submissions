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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (head != nullptr) {

            stack<ListNode*> st;
            ListNode* temp = head;
            int count = 0;

            while (temp != nullptr && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }

            if (count < k) {
                tail->next = head;
                break;
            }

            while (!st.empty()) {
                tail->next = st.top();
                tail = tail->next;
                st.pop();
            }

            head = temp;
        }

        tail->next = head;

        return dummy->next;
    }
};
