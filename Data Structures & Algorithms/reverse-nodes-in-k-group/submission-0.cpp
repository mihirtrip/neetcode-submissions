class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* ans = new ListNode(-1);
        ListNode* node = ans;

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
                node->next = head;
                break;
            }

            while (!st.empty()) {
                node->next = st.top();
                node = node->next;
                st.pop();
            }

            node->next = temp;

            head = temp;
        }

        return ans->next;
    }
};