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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        int max_sum = INT_MIN;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *next;
        while(slow){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        while(prev){
            max_sum = max(prev->val + head->val, max_sum);
            head = head->next;
            prev = prev->next;
        }
        return max_sum;
    }
};
