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
        ListNode *f = new ListNode();
        ListNode *p = f;
        int rem = 0;
        while(l1 != nullptr || l2 != nullptr || rem > 0){
            int digit = rem;
            if(l1 != nullptr) digit += l1->val;
            if(l2 != nullptr) digit += l2->val;
            p->val = digit % 10;
            
            //setup next iteration
            rem = digit/10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            if(l1 != nullptr || l2 != nullptr || rem > 0){
                p->next = new ListNode();
                p = p->next;
            }
        }
        
        return f;
    }
};
