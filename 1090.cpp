class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) { //O(N log N)
        vector<pair<int,int>> v;
        for(int i = 0; i < values.size(); i++){
            v.push_back({values[i], labels[i]});
        }
        
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first;
        };
        
        sort(v.begin(), v.end(), cmp);
        
        int val = 0; int num = 0;
        unordered_map<int,int> m;
        for(int i = 0; i < v.size(); i++){
            if(m[v[i].second] < useLimit){
                m[v[i].second]++;
                val += v[i].first;
                num++;
            }
            if(num == numWanted) break;
        }
        return val;
    }
};
