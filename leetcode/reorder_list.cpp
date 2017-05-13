class Solution {
    private:
        ListNode *reverse(ListNode* head) {
            ListNode *dummy = new ListNode(-INT_MAX);
            ListNode *prev = nullptr, *tmp = nullptr;
            while(head) {
                tmp = head->next;
                head->next = prev;
                prev = head;
                head = tmp;
            }
            return prev;
        }
    public:
        ListNode* reorderList(ListNode* head) {
            if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
                return nullptr;
            ListNode *slow = head, *fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            fast = reverse(slow->next);
            slow = head;
            ListNode *tmp_fast = nullptr;
            while(fast) {
                tmp_fast = fast->next;
                fast->next = slow->next;
                slow->next = fast;
                if(slow->next == nullptr) {
                    slow->next = fast;
                    break;
                }
                slow = fast->next;
                fast = tmp_fast;
            }
            return head;
        }
};
