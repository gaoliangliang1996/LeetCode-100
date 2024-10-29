class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* current = prev->next;

        for (int j = 0; j < right - left; ++j) {
            ListNode* nextNode = current->next;

            current->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy->next;
    }
};
