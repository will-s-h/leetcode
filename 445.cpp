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
        vector<int> v1; vector<int> v2;
        while(l1 != nullptr){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        vector<int> carry;
        
        if(v1.size() > v2.size()){
            vector<int> test = v2;
            v2 = v1;
            v1 = test;
        }
        
        for(int v : v1) carry.push_back(v);
        for(int i = 0; i < v2.size(); i++){
            if(i >= carry.size()){
                carry.push_back(v2[i]);
            } else {
                int sum = v2[i] + carry[i];
                carry[i] = sum % 10;
                int next = sum/10;
                if(next > 0 && i+1 >= carry.size()){
                    carry.push_back(next);
                } else if(next > 0){
                    carry[i+1] += next;
                }
            }
        }
        
        reverse(carry.begin(), carry.end());
        ListNode* cur = new ListNode(); ListNode* f = cur;
        for(int v : carry){
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        
        return (f != nullptr ? f->next : nullptr);
    }
};
