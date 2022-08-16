class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; int r = height.size()-1;
        int MA = 0;
        
        while(l < r){
            MA = max((r-l)*min(height[l], height[r]), MA);
            if(height[l] <= height[r]) l++;
            else r--;
        }
        
        return MA;
    }
};
