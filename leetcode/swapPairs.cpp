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
        ListNode* swapPairs(ListNode* head) {
            if(head==nullptr || head->next==nullptr)
                return head;

            ListNode* res = head->next;
            while(head && head->next) {
                ListNode* tmp = nullptr;
                if(head->next->next)
                     tmp = head->next->next;

                if(head->next && head->next->next && head->next->next->next) {
                    head->next->next = head;
                    head->next = tmp->next;
                }else {
                    head->next->next = head;
                    if(tmp)
                        head->next = tmp;
                    else
                        head->next = nullptr;
                }
                head = tmp;
            }
            return res;
        }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *grandChild = swapPairs(head->next->next);
        ListNode *child = head->next;
        child->next = head;
        head->next = grandChild;
        return child;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *reserve = nullptr;
        ListNode *a, *b, *p=head, *res=head->next;
        while((a=p) && (b=p->next)) {
             a->next = b->next;
             b->next = a;
             p = a->next;
             if(reserve != nullptr)
                 reserve->next = b;
             reserve = a;
        }
        return res;
    }
};
