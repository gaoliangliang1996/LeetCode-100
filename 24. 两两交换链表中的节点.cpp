class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            ListNode* first = current;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            pre->next = second;

            pre = current;
            current = current->next;
        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* first = head;
        ListNode* second = first->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};
