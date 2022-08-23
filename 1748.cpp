class Solution {
public:
    int sumOfUnique(vector<int>& nums) { //O(N+100)
        vector<int> times(101);
        for(int i : nums) times[i]++;
        int sum = 0;
        for(int i = 0; i <= 100; i++) if(times[i] == 1) sum += i;
        return sum;
    }
};
