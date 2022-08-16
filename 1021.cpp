class Solution {
public:
    string removeOuterParentheses(string s) {
        string o = "";
        int i = 0;
        while(i < s.length()){
            i++;
            int start = i;
            int count = 1;
            while(count > 0){
                if(s[i] == '(') count++;
                else count--;
                i++;
            }
            o += s.substr(start, i-start-1);
        }
        return o;
    }
};
