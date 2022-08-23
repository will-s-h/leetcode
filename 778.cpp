class Solution {
public:
    struct DSU {
        vector<int> e;
        DSU(int N) { e = vector<int>(N, -1); }

        // get representive component (uses path compression)
        int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

        bool same_set(int a, int b) { return get(a) == get(b); }

        int size(int x) { return -e[get(x)]; }

        bool unite(int x, int y) {  // union by size
            x = get(x), y = get(y);
            if (x == y) return false;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y]; e[y] = x; return true;
        }
    };
    
    int swimInWater(vector<vector<int>>& grid) { //O(N^2 log* N), using DSU
        int n = grid.size();
        vector<int> v(n*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                v[grid[i][j]] = i*n + j;
            }
        }
        
        DSU dsu(n*n);
        for(int h = 0; h < n*n; h++){
            int i = v[h]/n;
            int j = v[h]%n;
            if(i+1 < n && grid[i+1][j] < h) dsu.unite(i*n+j, (i+1)*n+j);
            if(i-1 >= 0 && grid[i-1][j] < h) dsu.unite(i*n+j, (i-1)*n+j);
            if(j+1 < n && grid[i][j+1] < h) dsu.unite(i*n+j, i*n+j+1);
            if(j-1 >= 0 && grid[i][j-1] < h) dsu.unite(i*n+j, i*n+j-1);
            if(dsu.same_set(0, n*n-1)) return h;
        }
        
        return -1;
    }
};
