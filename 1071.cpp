class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        for(int l = min(str1.length(), str2.length()); l > 0; l--){
            if(str1.length() % l != 0 || str2.length() % l != 0) continue;
            bool works = true;
            string code = str1.substr(0, l);
            
            for(int i = 0; i < str1.length(); i += l){
                for(int j = i; j < i + l; j++){
                    if(str1[j] != code[j-i]){
                        works = false;
                        break;
                    }
                } if(!works) break;
            }
            
            if(!works) continue;
            
            for(int i = 0; i < str2.length(); i += l){
                for(int j = i; j < i + l; j++){
                    if(str2[j] != code[j-i]){
                        works = false;
                        break;
                    }
                }
            }
            
            if(works) return code;
        }
        
        return "";
    }
};
