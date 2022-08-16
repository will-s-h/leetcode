class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int digits[10] = {}; for(int i : arr) digits[i]++;
        
        string sol = "";
        
        for(int h = 23; h >= 0; h--){
            bool valid = false;
            if(h%10 == h/10){
                if(digits[h/10] >= 2) valid = true;
            } else{
                if(digits[h%10] > 0 && digits[h/10] > 0) valid = true; 
            }
            
            if(valid){
                digits[h%10]--;
                digits[h/10]--;
                
                string maxminutes = "";
                for(int i = 5; i >= 0; i--){
                    if(digits[i] > 0){
                        maxminutes += to_string(i);
                        digits[i]--;
                        for(int j = 0; j < 10; j++){
                            if(digits[j] > 0) {maxminutes += to_string(j); break;}
                        }
                        break;
                    }
                }
                
                if(maxminutes != ""){
                    sol = to_string(h/10) + to_string(h%10) + ":" + maxminutes;
                    break;
                } else{
                    digits[h%10]++;
                    digits[h/10]++;
                }
            }
        }
        
        return sol;
    }
};
