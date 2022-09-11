class Solution {
public:
    
    struct data{
        vector<int> v;
        int c;
        int sum;
    };
    
    vector<vector<int>> combinationSum(vector<int>& cs, int t) { //O(???)
        vector<bool> pos(t+1); pos[0] = true;
        
        for(int c : cs){
            for(int i = c; i <= t; i++){
                if(pos[i-c]) pos[i] = true;
            }
        }
        
        vector<vector<int>> sol;
        
        queue<data> q; q.push({{}, 0, t});
        for(int i = 0; i < cs.size(); i++){
            while(!q.empty() && q.front().c == i){
                data d = q.front(); q.pop();
                
                if(d.sum == 0){
                    continue;
                }
                
                d.c++;
                while(d.sum >= 0 && pos[d.sum]){
                    q.push(d);
                    if(d.sum == 0) {sol.push_back(d.v); break;}
                    d.v.push_back(cs[i]);
                    d.sum -= cs[i];
                }
            }
        }
        
        return sol;
    }
};
