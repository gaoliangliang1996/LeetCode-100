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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        
        ListNode dummy(0);
        ListNode* node = &dummy;
        int carray = 0;

        while(l1 != nullptr && l2 != nullptr) {
            node->next = new ListNode((l1->val + l2->val + carray) % 10);
            carray = (l1->val + l2->val + carray) / 10;
            l1 = l1->next;
            l2 = l2->next;
            node = node->next;
        }

        if (l1 == nullptr && l2 == nullptr && carray != 0) {
            node->next = new ListNode(carray);
        }

        if (l2 == nullptr && l1 != nullptr) {
            if (carray == 0) {
                node->next = l1;
            }
            else {
                while(l1 != nullptr) {
                    node->next = new ListNode((l1->val + carray) % 10);
                    carray = (l1->val + carray) / 10;
                    l1 = l1->next;
                    node = node->next;
                }
                if (carray != 0) {
                    node->next = new ListNode(carray % 10);
                }
            }
        }

        if (l1 == nullptr && l2 != nullptr) {
            if (carray == 0) {
                node->next = l2;
            }
            else {
                while(l2 != nullptr) {
                    node->next = new ListNode((l2->val + carray) % 10);
                    carray = (l2->val + carray) / 10;
                    l2 = l2->next;
                    node = node->next;
                }
                if (carray != 0) {
                    node->next = new ListNode(carray % 10);
                }
            }
        }

        return dummy.next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0); // 创建一个虚拟头节点  
        ListNode *p = l1, *q = l2, *current = dummyHead; // 指针初始化  
        int carry = 0; // 进位  

        while (p != nullptr || q != nullptr || carry != 0) {  
            int x = (p != nullptr) ? p->val : 0; // 取l1当前位的值  
            int y = (q != nullptr) ? q->val : 0; // 取l2当前位的值  
            
            int sum = x + y + carry; // 计算本位的和  
            carry = sum / 10; // 更新进位  
            current->next = new ListNode(sum % 10); // 创建新节点，并连接到结果链表  
            current = current->next; // 移动到下一个节点  

            if (p != nullptr) p = p->next; // 移动指针  
            if (q != nullptr) q = q->next; // 移动指针  
        }  

        return dummyHead->next; // 返回虚拟节点的下一个节点作为结果  
    }
};
