class NumArray { //uses SegTree implementation from https://usaco.guide/gold/PURS?lang=cpp
private:
    int comb(int a, int b) {return a + b;}
    int len;
    vector<int> segtree;
    
public:
    NumArray(vector<int>& nums) { //O(N log N)
        len = nums.size();
        segtree = vector<int>(len * 2);
        for(int i = 0; i < nums.size(); i++){
            update(i, nums[i]);
        }
    }
    
    void update(int ind, int val) { //O(log N)
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
        }
    }
    
    int sumRange(int start, int end) { //O(log N)
        int sum = 0; end++;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if ((start & 1) != 0) {
                sum = comb(sum, segtree[start++]);
            }
            if ((end & 1) != 0) {
                sum = comb(sum, segtree[--end]);
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
