class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int len = nums.size(); if(len == 1) return false;
        int sum = 0; for(int num : nums) sum += num; if(sum == 0) return true;

        vector<int> v(sum+1);
        v[0] = 1; //bitmask yay

        for(int n : nums){
            for(int s = sum-n; s >= 0; s--){
                v[s+n] |= (2*v[s]);
            }
        }
        
        for(int s = 1; s < sum; s++){
            if((s*len % sum) != 0) continue;
            if(v[s] & (1 << (s*len/sum))) return true;
        }
        
        return false;
    }
};
