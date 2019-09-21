//https://leetcode.com/problems/sqrtx/

class Solution {
public:
        
    int mnewton(int x, double y, double e) { //поиск корня уравнения методом ньютона
           
    if (abs(y*y - x) < e) return y;
            
    double y2 = y - ((y*y - x)/(2*y));
        
    return mnewton(x, y2, e);
    }
    
    int mySqrt(int x) {
        return mnewton(x, 1, 0.00001);      
    }
};
