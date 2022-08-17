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
    ListNode* reverseKGroup(ListNode* head, int k) { //O(n) time, O(1) memory
        if(k == 1) return head;
        ListNode *n = new ListNode(0, head);
        ListNode *ans = n;
        
        int count = 0; //number of nodes in this group
        ListNode *pstart = n; //start of previous group of k
        ListNode *start = nullptr; //start of this group of k
        ListNode *prev = nullptr; //previous node
        
        n = n->next;
        while(n != nullptr){
            count++;
            ListNode *here = n; n = n->next;
            if(count == 1){
                start = here;
                prev = here;
            }
            else{ 
                if(count == k) {
                    start->next = here->next; //connect the start of group to start of next temporarily
                    pstart->next = here; //permanently connect previous start to end
                    pstart = start; //update previous start
                    count = 0; //update count
                }
                here->next = prev; //connect this node to previous one
                prev = here; //update previous node
            }
        }
        
        //if the final group has len < k, reverse the process
        if(count < k && count > 1){
            n = prev->next; prev->next = nullptr; count--;
            while(count > 1){
                ListNode* nextn = n->next;
                n->next = prev;
                prev = n;
                n = nextn;
                count--;
            }
        }
        
        return ans->next;
    }
};
