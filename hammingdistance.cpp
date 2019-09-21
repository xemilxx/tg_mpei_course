//https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int k = 0;
        int p = x^y;
        while (p) {
            k++;
            p &= (p - 1);
        }
        return k;    
    }
};
