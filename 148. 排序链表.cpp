// 用到了归并排序的思想
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = nullptr;

        first = sortList(first);
        second = sortList(second);

        return merge(first, second);
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while (first && second) {
            if (first->val < second->val) {
                tail->next = first;
                first = first->next;
            }
            else {
                tail->next = second;
                second = second->next;
            }
            
            tail = tail->next;
        }

        if (first)
            tail->next = first;

        if (second)
            tail->next = second;

        return dummy->next;
    }
};
