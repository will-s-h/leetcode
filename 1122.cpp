class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) { //O(N log N)
        unordered_map<int,int> m;
        for(int i = 0; i < arr2.size(); i++){
            m[arr2[i]] = i;
        }
        
        vector<int> num(arr2.size());
        vector<int> other;
        for(int i : arr1){
            if(m.count(i)) num[m[i]]++;
            else other.push_back(i);
        }
        
        sort(other.begin(), other.end());
        vector<int> sol;
        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < num[i]; j++) sol.push_back(arr2[i]);
        }
        for(int i : other) sol.push_back(i);
        return sol;
    }
};
