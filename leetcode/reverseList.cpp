/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *dummy_head = new ListNode(-INT_MAX);
        ListNode *tmp;
        dummy_head->next = head;
        ListNode *prev = dummy_head;
        while(head != nullptr) {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        dummy_head->next->next = nullptr;
        return prev;
    }
};
