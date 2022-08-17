class Solution {
public:
    vector<string> generateParenthesis(int n) { //O(4^n / √n), nth catalan number * n, 8 ms
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
    
    vector<string> slow(int n) { //O(n * n!), 30 ms
        vector<int> a; for(int i = 1; i <= n; i++) a.push_back(i);
        vector<string> ans; unordered_map<string, bool> seen;
        do{
            int maxA = -1;
            int num = 0; string s = "";
            for(int i = 0; i < n; i++){
                maxA = max(maxA, a[i]);
                while(num < maxA) {s += '('; num++;}
                s += ')';
            }
            if(seen.count(s) < 1){
                seen[s] = true;
                ans.push_back(s);
            }
        } while(next_permutation(a.begin(), a.end()));
        
        return ans;
    }
};
