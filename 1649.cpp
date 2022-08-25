template<class T>
class SumSegmentTree { //implementation taken from https://usaco.guide/gold/PURS?lang=cpp
	private:
		T comb(T a, T b) { return a + b; }
		const T DEFAULT = 0;

		vector<T> segtree;
		int len;
	public:
		SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) { }

		void set(int ind, T val) {
			assert(0 <= ind && ind < len);
			ind += len;
			segtree[ind] = val;
			for (; ind > 1; ind /= 2) {
				segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
			}
		}

		T range_sum(int start, int end) {
			assert(0 <= start && start < len && 0 < end && end <= len);
			T sum = DEFAULT;
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

class Solution {
public:
    const int M = 1e9 + 7;
    const int MN = 1e5;
    int createSortedArray(vector<int>& instructions) { //O(N log N) using a segment tree
        SumSegmentTree<int> tree(MN+1);
        int cost = 0;
        vector<int> v(MN+1);
        for(int i : instructions){
            int lt = tree.range_sum(1, i);
            int gt = (i < MN) ? tree.range_sum(i+1, MN+1) : 0;
            cost = (cost + min(lt, gt)) % M;
            v[i]++;
            tree.set(i, v[i]);
        }
        return cost;
    }
};
