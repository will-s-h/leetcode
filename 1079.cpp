class Solution {
public:
    int fact(int x){
        if(x <= 1) return 1;
        return x * (x-1) * fact(x-2);
    }
    
    int numTilePossibilities(string tiles) { //O(N*2^N)
        unordered_map<char, int> m;
        int code = 1;
        for(int i = 0; i < tiles.length(); i++){
            if(m.count(tiles[i]) < 1){
                m[tiles[i]] = code;
                code *= 8;
            }
        }
        
        unordered_set<int> s;
        int total = 0;
        for(int i = 1; i < (1 << tiles.length()); i++){
            int subset = 0;
            int n = 0;
            for(int p = 0; p < tiles.length(); p++){
                if(i & (1 << p)){
                    subset += m[tiles[p]];
                    n++;
                }
            }
            if(s.count(subset) < 1){
                s.insert(subset);
                int nfact = fact(n);
                while(subset > 0){
                    nfact /= fact(subset % 8);
                    subset /= 8;
                }
                total += nfact;
            }
        }
        
        return total;
    }
};
