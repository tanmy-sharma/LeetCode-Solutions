class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return head;
        }
        deque <ListNode*> dq;
        ListNode *h = head;
        while(head){
            dq.push_back(head);
            head = head->next;
        }
        k = k % dq.size();
        while(k--){
            ListNode *last = dq.back();
            ListNode *new_Node = new ListNode(last->val);
            new_Node->next = h;
            h = new_Node;
            dq.push_front(new_Node);
            dq.pop_back();
            dq.back()->next = nullptr;
        }
        return h;
    }
};
