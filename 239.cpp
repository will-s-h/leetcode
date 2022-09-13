class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { //O(N)
        vector<int> ans;
        deque<pair<int,int>> d;
        for(int i = 0; i < nums.size(); i++){
            while(!d.empty() && d.back().first < nums[i]) d.pop_back();
            d.push_back({nums[i], i});
            while(!d.empty() && d.front().second <= i-k) d.pop_front();
            if(i >= k-1) ans.push_back(d.front().first);
        }
        return ans;
    }
};
