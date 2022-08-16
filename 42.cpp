class Solution {
public:
    int trap(vector<int>& height) {
        int maxheightL[height.size()];
        int maxheightR[height.size()];
        
        int max = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] > max) max = height[i];
            maxheightL[i] = max;
        }
        
        max = 0;
        for(int i = height.size()-1; i >= 0; i--){
            if(height[i] > max) max = height[i];
            maxheightR[i] = max;
        }
        
        int area = 0;
        for(int i = 0; i < height.size(); i++){
            area += std::max(std::min(maxheightR[i], maxheightL[i])-height[i],0);
        }
        return area;
    }
};
