/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n < 0) {
            return nullptr;
        }

        ListNode* node = head;
        int count = 0;
        while(node != nullptr) {
            count++;
            node = node->next;
        }

        if (n > count) {
            return nullptr;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy, *slow = &dummy;
        while (n-- >= 0) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* todelete = slow->next;

        if (todelete != nullptr) {
            slow->next = slow->next->next;
            delete todelete;
        }
        
        return dummy.next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n < 0) {
            return nullptr;
        }

        ListNode* node = head;
        int count = 0;
        while(node != nullptr) {
            count++;
            node = node->next;
        }

        if (n > count) {
            return nullptr;
        }

        stack<ListNode*> s;
        ListNode dummy(0, head);
        node = &dummy;

        while (node != nullptr) {
            s.push(node);
            node = node->next;
        }

        while (n != 0) {
            s.pop();
            n--;
        }

        ListNode* prev = s.top();
        prev->next = prev->next->next;
        return dummy.next;
    }
};
