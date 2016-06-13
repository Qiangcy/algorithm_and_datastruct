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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int list_A_len = 0, list_B_len = 0, diff = 0;
        ListNode *tmp_A = headA;
        ListNode *tmp_B = headB;
        while(tmp_A) {
            tmp_A = tmp_A->next;
            ++list_A_len;
        }
        while(tmp_B) {
            tmp_B = tmp_B->next;
            ++list_B_len;
        }
        diff = list_A_len - list_B_len;
        if(diff > 0) {
            while(diff--) {
                headA = headA->next;
            }
        }else {
            while(diff++) {
                headB = headB->next;
            }
        }
        while(headA && headB) {
            if(headA == headB) {
                 return headA;
            }else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};


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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning,
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
}
};
