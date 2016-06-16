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
        ListNode* mergeKLists(vector<ListNode*> &lists) {
            if(!lists.size())
                return nullptr;
            int i;
            for(i=0; i<lists.size()-1; ++i) {
                lists[i+1] = mergeTwoLists(lists[i], lists[i+1]);
            }
            return lists[i];
        }
    private:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *dummy = new ListNode(-INT_MAX);
            ListNode *res = dummy;
            while(l1!=nullptr && l2!=nullptr) {
                if(l1->val < l2->val) {
                    dummy->next = l1;
                    l1 = l1->next;
                }else {
                    dummy->next = l2;
                    l2 = l2->next;
                }
                dummy = dummy->next;
            }
            dummy->next = (l1!=nullptr?l1:l2);
            return res->next;
        }

};
