class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) { //O(n log n)
        int pos = 0;
        int fuel = startFuel;
        int num = 0;
        int s = 0;
        priority_queue<int> pq;
        
        while(pos < target && fuel > 0){
            pos += fuel;
            fuel = 0;
            
            //if reached, return number of refills
            if(pos >= target) return num; 
            
            //else, refill with maximum pump
            while(s < stations.size() && stations[s][0] <= pos){
                pq.push(stations[s][1]);
                s++;
            }
            
            if(!pq.empty()){
                fuel += pq.top(); pq.pop();
                num++;
            }
        }
        
        return -1;
    }
  
    int slowDP(int target, int startFuel, vector<vector<int>>& stations) { //O(N^2)
        vector<vector<int>> s; s.push_back({0,0});
        for(vector<int> station : stations){
            if(station[0] < target) s.push_back(station);
        }
        s.push_back({target, 0});
        int n = s.size();
        
        vector<vector<long long>> dp(n, vector<long long>(n, -1)); 
        //dp[i][j] arrive at gas station j with dp[i][j] liters, with i previous refills 
        
        dp[0][0] = startFuel;
        
        for(int i = 0; i < n; i++){ //number of refills
            dp[i][0] = dp[0][0];
            for(int j = 1; j < n; j++){ //gas station #
                //consider refilling at gas station j-1
                if(i > 0 && dp[i-1][j-1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + s[j-1][1] - (s[j][0] - s[j-1][0]));
                
                //consider not refilling at gas station j-1
                if(dp[i][j-1] > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] - (s[j][0] - s[j-1][0]));
                if(j == n-1 && dp[i][j] >= 0) return i;
            }
        }
        
        return -1;
    }
};
