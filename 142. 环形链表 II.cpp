class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;

        ListNode* current = head;
        while (current != nullptr) {
            if (nodes.find(current) != nodes.end()) {
                return current;
            }

            nodes.insert(current);
            current = current->next;
        }

        return nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }

                return fast;
            }
        }

        return nullptr;
    }
};
