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
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if(m == n || head->next==nullptr)
                return head;

            int idx = 1;
            ListNode* p = head;
            ListNode* mark_head = nullptr;
            while(p) {
                if(idx==m-1 || m==1)
                    mark_head = p;

                if(idx == m) {
                    ListNode* pre = p;
                    p = p->next;
                    ListNode* tmp;
                    for(;;) {
                        tmp = p->next;
                        p->next = pre;
                        pre = p;
                        p = tmp;

                        idx++;
                        if(idx == n) {
                            if(m == 1) {
                                mark_head->next = p;
                                return pre;
                            }
                            mark_head->next->next = p;
                            mark_head->next = pre;
                            return head;
                        }
                    }
                }

                idx++;
                p = p->next;
            }
            return head;
        }
};
