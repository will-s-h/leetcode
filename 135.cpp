class Solution {
public:
    int candy(vector<int>& ratings) { //O(N)
        int n = ratings.size();
        vector<int> l2r(n); l2r[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]) l2r[i] = l2r[i-1]+1;
            else l2r[i] = 1;
        }
        
        int sum = l2r[n-1];
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) l2r[i] = max(l2r[i], l2r[i+1]+1);
            sum += l2r[i];
        }
        
        return sum;
    }
};
