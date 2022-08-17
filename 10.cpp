class Solution {
public:
    bool isMatch(string s, string p) {
        vector<pair<char, bool>> v; //vector of {character, has *}
        v.push_back({'0', false}); //make it one-indexed
        int lens = s.length(); int lenp = p.length();
        
        int i = 0;
        while(i < lenp){ //converting string p into vector of clearer instructions
            if(i == lenp-1 || p[i+1] != '*'){
                v.push_back({p[i], false});
                i++;
            } else {
                v.push_back({p[i], true});
                i += 2;
            }
        }
        
        //O(n*m)
        s = " " + s;
        int lenv = v.size()-1;
        vector<vector<bool>> dp(lens+1, vector<bool>(lenv+1)); //dp array where dp[i][j] is true if s[1...i] satisfies instructions v[1...j]
        dp[0][0] = true;
        
        for(int j = 1; j <= lenv; j++){
            if(v[j].second) dp[0][j] = dp[0][j-1]; //if *, having 0 of this particular character is an option
            for(int i = 1; i <= lens; i++){
                if(s[i] != v[j].first && v[j].first != '.' && !v[j].second) continue;
                
                //either same letter, or this instruction has *
                if(!v[j].second) dp[i][j] = dp[i-1][j-1]; //only same letter
                else{ //instruction has *
                    if(s[i] == v[j].first || v[j].first == '.'){ //same letter
                        dp[i][j] = (dp[i-1][j-1] || dp[i-1][j]); //consider having s[i] as the only letter satisfying instruction j, or having previous characters also satisfy instruction j
                    }
                    dp[i][j] = (dp[i][j] || dp[i][j-1]); //consider not using instruction j at all, since it has *
                }
            }
        }
        
        return dp[lens][lenv];
    }
};
