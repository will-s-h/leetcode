class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = fruits[0];
        int ind1 = 0;
        int second = -1;
        int ind2 = -1;
        int cur = 1;
        int total = 1;
        int i = 1;
        
        for(i = 1; i < fruits.size(); i++){
            cur++;
            total++;
            if(fruits[i] != first){
                second = fruits[i];
                ind2 = i;
                break;
            }
        }
        
        i++;
        
        for(i; i < fruits.size(); i++){
            if(fruits[i] == first){
                if(ind1 < ind2) ind1 = i;
                cur++;
                total = max(total, cur);
                continue;
            }
            if(fruits[i] == second){
                if(ind2 < ind1) ind2 = i;
                cur++;
                total = max(total, cur);
                continue;
            }
            
            total = max(total, cur);
            cur = i - max(ind1, ind2) + 1;
            second = (ind1 > ind2 ? first : second);
            ind2 = max(ind1, ind2);
            first = fruits[i];
            ind1 = i;
        }
        
        return total;
    }
};
