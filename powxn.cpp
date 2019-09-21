//https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        double t = myPow(x, n/2);
        if (n % 2 == 0) return t * t; //степень четная
        else if (n > 0) return x * t * t; //степень нечетная
        else return (t * t) / x; //степень отрицательная
    }
};
