class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> nodeMap;
        Node* node = head;
        while (node) {
            nodeMap[node] = new Node(node->val);
            node = node->next;
        }

        node = head;
        while (node) {
            nodeMap[node]->next = nodeMap[node->next];
            nodeMap[node]->random = nodeMap[node->random];
            node = node->next;
        }

        return nodeMap[head];
    }
};
