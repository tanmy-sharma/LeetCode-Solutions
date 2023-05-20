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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode *even = nullptr, *odd = nullptr, *evenHead = nullptr, *oddHead = nullptr;
        int i = 1;
        while(head){
            if(i % 2 != 0){
                if(!oddHead){
                    oddHead = head;
                    odd = oddHead;
                }
                else{
                    odd->next = head;
                    odd = odd->next;
                }
            }
            else{
                if(!evenHead){
                    evenHead = head;
                    even = evenHead;
                }
                else{
                    even->next = head;
                    even = even->next;
                }
            }
            i++;
            head = head->next;
        }
        odd->next = evenHead;
        even->next = nullptr;
        return oddHead;
    }
};
