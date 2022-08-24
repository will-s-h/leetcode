class Solution {
public:
    bool isPowerOfThree(int n) { //O(calculating log(n))
        return fmod(log(n)/log(3.0)+0.5e-9,1.0) <= 1e-9; //fmod is float modulus
    }
};
