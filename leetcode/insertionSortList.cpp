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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *res = new ListNode(-1);
        ListNode *dummpy = new ListNode(head->val);
        res->next = dummpy;
        for(head=head->next; head!=nullptr; head=head->next) {
            if(head->val <= dummpy->val) {
                ListNode *tmp = new ListNode(head->val);
                tmp->next = dummpy;
                res->next = tmp;
                dummpy = tmp;
            } else{
                ListNode *node = new ListNode(head->val);
                ListNode *tmp = dummpy;
                while((node->val > tmp->val) && tmp->next!=nullptr && (node->val > tmp->next->val))
                    tmp = tmp->next;
                node->next = tmp->next;
                tmp->next  = node;
            }
        }
        return res->next;
    }
};

class Solution {
    public:
        ListNode *insertionSortList(ListNode *head) {
            if(!head)
                return NULL;
            ListNode *h=new ListNode(0);
            ListNode *cur=head;
            ListNode *prev=h;
            ListNode *next=NULL;
            while(cur){
                next=cur->next;
                if(!prev||!prev->next||prev->next->val>=cur->val)prev=h;//I add this line
                while(prev->next&&prev->next->val<cur->val){
                    prev=prev->next;
                }
                cur->next=prev->next;
                prev->next=cur;
                //pre = helper; I erase this line;
                cur=next;
            }
            return h->next;
        }
};
