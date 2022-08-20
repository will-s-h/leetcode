class Solution {
public:
    
    long long round(double x){
        return (long long) (x*1e8 + 0.5);
    }
    
    int maxPoints(vector<vector<int>>& points) { //O(N^2), doesn't deal with duplicate points, but those testcases are now deprecated
        unordered_map<long long, unordered_map<long long, int>> m;
        int maxP = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                double dx = points[j][0] - points[i][0];
                double dy = points[j][1] - points[i][1];
                long long slope = (dx == 0 ? LLONG_MAX : round(dy/dx));
                long long inter = (dx == 0 ? points[i][0] : round((points[i][1]*dx - points[i][0]*dy)/dx));
                m[slope][inter]++;
                maxP = max(maxP, m[slope][inter]);
            }
        }
        
        return (1 + sqrt(1+8*maxP))/2;
    }
};
