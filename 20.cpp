class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()) return false;
                char c = st.top(); st.pop();
                if(s[i] == ')' && c != '(') return false;
                if(s[i] == '}' && c != '{') return false;
                if(s[i] == ']' && c != '[') return false;
            } else st.push(s[i]);
        }
        return st.empty();
    }
};
