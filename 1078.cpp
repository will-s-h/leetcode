class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) { //O(N)
        istringstream stream(text);
        string token;
        bool prev = false;
        bool getThis = false;
        vector<string> ans;
        
        while(getline(stream, token, ' ')){
            if(getThis){
                ans.push_back(token);
            }
            if(prev && token == second){
                getThis = true;
            } else{
                getThis = false;
            }
            if(token == first){
                prev = true;
            } else {
                prev = false;
            }
        }
        
        return ans;
    }
};
