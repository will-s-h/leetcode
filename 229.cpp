class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) { //O(N) time, O(1) memory
        //modification of Boyer-Moore Majority Votes Algorithm
        int cnt1, cnt2; cnt1 = cnt2 = 0;
        int elem1, elem2; elem1 = elem2 = INT_MIN;
        
        for(int e : nums) {
            if(e == elem1) cnt1++;
            else if(e == elem2) cnt2++;
            else if(cnt1 == 0) {elem1 = e; cnt1 = 1;}
            else if(cnt2 == 0) {elem2 = e; cnt2 = 1;}
            else {cnt1--; cnt2--;}
        }

        cnt1 = cnt2 = 0;
        
        for(int e : nums) {
            if(e == elem1) cnt1++;
            else if(e == elem2) cnt2++;
        }
        
        vector<int> ans;
        if(cnt1 > nums.size()/3) ans.push_back(elem1);
        if(cnt2 > nums.size()/3) ans.push_back(elem2);
        
        return ans;
    }
};
