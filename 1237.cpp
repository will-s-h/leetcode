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
    vector<vector<int>> findSolution(CustomFunction& c, int z) { //O(x+y)
        vector<vector<int>> sol;
        int y = 1000;
        for(int x = 1; x <= 1000; x++){
            while (y > 1 && c.f(x,y) > z) y--;
            if(c.f(x,y) == z) sol.push_back({x,y});
        } 
        return sol;
    }
};
