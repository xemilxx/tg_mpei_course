//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    
    int uniquePaths(int m, int n) {
       
        /*
        Всего есть (m + n - 2) шагов в каждом пути, (m - 1) из которых вниз  и (n - 1) вправо.
        Получается, ответом является число сочетаний.
        */
        
        long c = 1;
        if (m > n) {
            swap(m, n);
        }
        n--;
        for (size_t i = 1; i < m; i++) {
            c = c * (n + i) / i;
        }
        return c;
                
    }
};
