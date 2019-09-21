//https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    
    int trailingZeroes(int n) { 
        int k = 0;
        long x = 5;
        while (x <= n) {
            k += n/x;
            x *= 5;
        }
        return k;
    }
};
