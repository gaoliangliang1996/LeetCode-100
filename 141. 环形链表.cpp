class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) { 
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && slow != nullptr && slow->next != nullptr) {
            fast = fast->next;
            slow = slow->next->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
};
