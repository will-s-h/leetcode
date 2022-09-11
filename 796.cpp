class Solution {
public:
    int pow(int p, int n, int M){ //p^n mod M
        if(n == 0) return 1;
        else if(n == 1) return p%M;
        else if(n % 2 == 0){
            int sq = pow(p, n/2, M);
            return (int) ((long long) sq * sq % M);
        }
        return ((long long) p*pow(p, n-1, M))%M;
    }
    
    const int M = 1e9 + 7;
    const int p = 113;
    
    bool rotateString(string s, string goal) { //O(N) using hashing
        if(s.length() != goal.length()) return false;
        long long PtoN = pow(p, goal.length(), M);
        
        long long hash = 0;
        long long g = 0;
        
        for(int i = 0; i < s.length(); i++){
            hash = (hash*p) % M; hash = (hash+(s[i]-'a')) % M;
            g = (g*p) % M; g = (g+(goal[i]-'a')) % M;
        }
        
        if(g == hash) return true;
        
        for(char x : s){
            hash = (hash*p) % M;
            hash = (hash - (PtoN*(x-'a') % M)) % M;
            if(hash < 0) hash = (hash + M) % M;
            hash = (hash + (x-'a')) % M;
            if(g == hash) return true;
        }
        
        return false;
    }
    
    bool rotateStringKMP(string s, string goal) { //O(N) with KMP
        if(s.length() != goal.length()) return false;
        s = goal + "#" + s + s.substr(0, s.length()-1);
        
        vector<int> lps(s.length());
        for(int i = 1; i < s.length(); i++){
            int j = lps[i-1];
            while(j > 0 && s[i] != s[j]){
                j = lps[j-1];
            }
            if(s[i] == s[j]) lps[i] = j+1;
            if(lps[i] == goal.length()) return true;
        }
        return false;
    }
};
