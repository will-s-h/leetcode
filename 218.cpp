class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) { //O(n log n)
        vector<vector<int>> sol;
        
        multiset<int> hs; hs.insert(0);
        priority_queue<pair<int,int>> ends;
        
        int i = 0;
        
        while(i < buildings.size()){
            int l = buildings[i][0]; int r = buildings[i][1];
            int maxh = buildings[i][2];
            int prev_maxh = *(--hs.end());
            
            while(i < buildings.size() && buildings[i][0] == l){
                int r = buildings[i][1]; int h = buildings[i][2];
                hs.insert(h);
                maxh = max(maxh, h);
                ends.push({-r, -h});
                i++;
            }
            
            i--;
            
            if(maxh > prev_maxh){
                sol.push_back({l, maxh});
            }
            
            while(!ends.empty() && (i == buildings.size()-1 || -ends.top().first < buildings[i+1][0])){
                pair<int, int> p = ends.top(); ends.pop();
                int rend = -p.first; int hend = -p.second;
                hs.erase(hs.find(hend));
                if(*(--hs.end()) < hend){
                    sol.push_back({rend, *(--hs.end())});
                }
            }
            
            i++;
        }
        
        return sol;
    }
};
