/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    
    vector<vector<int>> sol;
    vector<int> seenx;
    
    bool findy(CustomFunction& c, int x, int z){
        if(seenx[x]) return (seenx[x] > 0);
        int loy = 1;
        int hiy = 1000;
        int lobound = 1001;
        
        //find the lower bound
        while(loy <= hiy){
            int mid = loy + (hiy - loy) / 2;
            int val = c.f(x, mid);
            if(val >= z){
                lobound = mid;
                hiy = mid - 1;
            } else {
                loy = mid + 1;
            }
        }
        
        if(lobound == 1001) {
            seenx[x] = -2; //all values are less
            return false;
        } else if(lobound == 1 && c.f(x, 1) > z){
            seenx[x] = -1; //all values are greater
            return false;
        }
        
        //find the upper bound
        loy = lobound;
        hiy = 1000;
        int hibound = lobound;
        while(loy <= hiy){
            int mid = loy + (hiy - loy) / 2;
            int val = c.f(x, mid);
            if(val > z){
                hiy = mid - 1;
            } else{
                hibound = mid;
                loy = mid + 1;
            }
        }
        
        for(int i = lobound; i <= hibound; i++){
            if(c.f(x, i) == z) sol.push_back({x, i});
        }
        
        seenx[x] = 1;
        return true;
    }
    
    vector<vector<int>> findSolution(CustomFunction& c, int z) { //quite slow, O(N^2 log N), but still passes
        sol = vector<vector<int>>();
        seenx = vector<int>(1001);
        int lox = 1;
        int hix = 1000;
        
        for(int i = lox; i <= hix; i++){
            findy(c, i, z);
        }
        
        return sol;
    }
};
