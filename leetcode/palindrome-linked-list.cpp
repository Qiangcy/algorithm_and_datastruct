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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse_list(slow);
        slow = slow->next;
        while(slow) {
            if(head->val != slow->val)
                return false;

            slow = slow->next;
            head = head->next;
        }
        return true;
    }
private:
    ListNode *reverse_list(ListNode *slow) {
        ListNode *prev = slow;
        ListNode *cur, *tmp_next = prev->next;
        while(tmp_next) {
            cur = tmp_next;
            tmp_next = cur->next;
            cur->next = prev;
            prev = cur;
        }
        slow->next->next = nullptr;
        return cur;
    }
};




class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};
