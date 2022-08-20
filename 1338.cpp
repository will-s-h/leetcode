class Solution {
public:
    int minSetSize(vector<int>& arr) { //O(N log N). Note that due to the constraints of the problem, you can also do an O(N) counting sort, but it's likely slower
        unordered_map<int, int> m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        
        auto cmp = [](pair<int,int>& p1, pair<int,int>& p2){
            return p1.second > p2.second;
        };
        
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        
        int sum = 0; int num = 0;
        for(pair<int,int> p : v){
            sum += p.second; num++;
            if(sum >= (arr.size()+1)/2) return num;
        }
        return num;
    }
};
