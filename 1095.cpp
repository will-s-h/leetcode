/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    unordered_map<int,int> calls;
    
    int peakIndexInMountainArray(MountainArray &ma) {
        //divide into three segments, the peak is in whichever 2/3 is 
        
        int lo = 0;
        int hi = ma.length()-1;
        int ans = 0;
        
        while(lo < hi){
            int m1 = lo + (hi - lo + 2) / 3;
            int m2 = lo + (hi - lo + 1) * 2 / 3;
            
            int a[4] = {lo, m1, m2, hi};
            int vals[4] = {};
            
            for(int i = 0; i < 4; i++){
                if(calls.count(a[i]) > 0) vals[i] = calls[a[i]];
                else{
                    vals[i] = ma.get(a[i]);
                    calls[a[i]] = vals[i];
                }
            }
            
            if(vals[0] > vals[1]){
                ans = lo;
                hi = m1-1;
            } else if(vals[1] >= vals[2]){
                ans = m1;
                hi = m2-1;
            } else if(vals[2] > vals[3]){
                ans = m2;
                lo = m1+1;
            } else {
                ans = hi;
                lo = m2+1;
            }
        }
        
        return ans;
    }
    
    int findInMountainArray(int target, MountainArray &ma) {
        int peak = peakIndexInMountainArray(ma);
        calls = unordered_map<int,int>();
        
        //next, binary search in each half of the mountain
        int lo = 0;
        int hi = peak;
        int ans = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int val = 0; 
            if(calls.count(mid) > 0) val = calls[mid];
            else{
                val = ma.get(mid);
                calls[mid] = val;
            }
            if(val == target){
                ans = mid;
                hi = mid-1;
            } else if(val > target){
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        if(ans != -1) return ans;
        
        lo = peak;
        hi = ma.length()-1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int val = 0; 
            if(calls.count(mid) > 0) val = calls[mid];
            else{
                val = ma.get(mid);
                calls[mid] = val;
            }
            if(val == target){
                ans = mid;
                hi = mid-1;
            } else if(val < target){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
};
