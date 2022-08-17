class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(); int m = words.size(); int w = words[0].length();
        if(n < w*m) return vector<int>();
        
        unordered_map<string, int> ws;
        vector<int> count(m);
        for(int i = 0; i < m; i++){
            if(ws.count(words[i])){
                count[ws[words[i]]]++;
            } else {
                ws[words[i]] = i;
                count[i] = 1;
            }
        }
        
        vector<int> sol;
        
        for(int i = 0; i < w; i++){ //start position
            vector<int> contains(m);
            queue<int> q; //running queue of words currently in this segment
            for(int j = i; j <= n-w; j += w){ //start of each word
                if(q.size() == m){
                    int toRem = q.front(); q.pop(); //word to remove
                    if(toRem != INT_MAX) contains[toRem]--;
                }
                
                string word = s.substr(j, w);
                int toAdd = INT_MAX; //word to add
                if(ws.count(word)) {
                    toAdd = ws[word]; 
                    contains[toAdd]++;
                }
                q.push(toAdd);
                
                bool works = true;
                for(int i = 0; i < m; i++){
                    if(contains[i] != count[i]){
                        works = false;
                        break;
                    }
                }
                
                if(works) sol.push_back(j - w*(m-1));
            }
        }
        
        return sol;
    }
};
