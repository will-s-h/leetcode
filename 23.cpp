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
    
    struct cmp
    {
        bool operator()(const ListNode* l, const ListNode* r) const
        {
            return l->val > r->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(ListNode* l : lists){
            if(l != nullptr) pq.push(l);
        }
        
        ListNode* sol = new ListNode();
        ListNode* f = sol;
        
        while(!pq.empty()){
            ListNode* p = pq.top(); pq.pop();
            sol->next = new ListNode(p->val);
            sol = sol->next;
            if(p->next != nullptr) pq.push(p->next); 
        }
        
        return f->next;
    }
};
