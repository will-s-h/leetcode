class Solution {
public:
    int strStr(string h, string ne) { //O(n+m), uses KMP, actually slower with LeetCode's test cases
        if(ne == "") return 0;
        if(h == "") return -1;
        int n = (int) h.length(); int m = (int) ne.length();
        vector<int> pi_n(m);
        for(int i = 1; i < m; i++){
            int j = pi_n[i-1];
            while(j > 0 && ne[i] != ne[j]) j = pi_n[j-1];
            if(ne[i] == ne[j]) pi_n[i] = j+1;
        }
        
        vector<int> pi_h(n); 
        pi_h[0] = (h[0] == ne[0]) ? 1 : 0; if(pi_h[0] == 1 && m == 1) return 0;
        for(int i = 1; i < n; i++){
            int j = pi_h[i-1];
            while(j > 0 && h[i] != ne[j]) j = pi_n[j-1];
            if(h[i] == ne[j]) pi_h[i] = j+1;
            if(pi_h[i] == m) return i-m+1;
        }
        return -1;
    }
  
    int slow(string haystack, string needle) { //O(nm), naive
        int n = (int) haystack.length(); int m = (int) needle.length();
        for(int i = 0; i <= n-m; i++){
            bool works = true;
            for(int j = i; j < i+m; j++){
                if(haystack[j] != needle[j-i]){
                    works = false;
                    break;
                }
            }
            if(works) return i;
        }
        return -1;
    }
};
