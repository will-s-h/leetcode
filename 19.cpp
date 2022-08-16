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
        ListNode* f = new ListNode();
        vector<ListNode*> v;
        ListNode* cur = head;
        
        while(cur != nullptr){
            f->next = new ListNode(cur->val);
            f = f->next;
            cur = cur->next;
            v.push_back(f);
        }
        
        if(v.size() == 1) return nullptr;
        if(n == 1){
            v[v.size()-2]->next = nullptr;
        } else if(n == v.size()){
            v[0] = v[1];
        } else {
            v[v.size()-n-1]->next = v[v.size()-n+1];
        }
        return v[0];
    }
};
