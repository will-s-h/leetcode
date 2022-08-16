class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //divide into three segments, the peak is in whichever 2/3 is 
        
        int lo = 0;
        int hi = arr.size()-1;
        int ans = 0;
        
        while(lo < hi){
            int m1 = lo + (hi - lo + 2) / 3;
            int m2 = lo + (hi - lo + 1) * 2 / 3;
            
            if(arr[lo] > arr[m1]){
                ans = lo;
                hi = m1-1;
            } else if(arr[m1] >= arr[m2]){
                ans = m1;
                hi = m2-1;
            } else if(arr[m2] > arr[m1]){
                ans = m2;
                lo = m1+1;
            } else {
                ans = hi;
                lo = m2+1;
            }
        }
        
        return ans;
    }
};
