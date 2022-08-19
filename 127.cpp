class Solution {
public:
    bool offByOne(string& s, string& t){
        bool off = false;
        for(int i = 0; i < s.length(); i++){
            if(!off && s[i] != t[i]) off = true;
            else if(off && s[i] != t[i]) return false;
        }
        return off;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { //straightforward BFS
        int n = wordList.size(); wordList.push_back(beginWord);
        vector<int> visited(n+1);
        queue<int> q; q.push(n);
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(int i = 0; i < wordList.size(); i++){
                if(!visited[i] && offByOne(wordList[x], wordList[i])){
                    visited[i] = visited[x] + 1;
                    q.push(i);
                    if(wordList[i] == endWord) return visited[i]+1;
                }
            }
        }
        
        return 0;
    }
};
