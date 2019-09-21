//https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        int f1 = 0; 
        int f2 = 1;
        int s = 0;
        if (N == 0) return 0; 
        else {
         for (int i = 2; i <= N; i++) {
            s = f1 + f2;
            f1 = f2;
            f2 = s;
         }
        return f2;
        }
    }
};
