// https://cloud.tencent.com/developer/article/2286581
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB) {
            pA = pA == nullptr? headB : pA->next;
            pB = pB == nullptr? headA : pB->next;
        }

        return pA;
    }
};
