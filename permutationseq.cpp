//https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    
    int factorial(int n) { //чтобы посчитать общее количество перестановок
        if (n == 0 || n == 1) return 1;            
        else return n*factorial(n-1);
    }
    
    string getPermutation(int n, int k) {
        
        int f = factorial(n);
        
        vector<int> perest(n); //сами перестановки
        
        for (int i = 1; i <= n ; i++) {
            perest[i-1] = i;
        }
        
        string s = "";
        s.resize(n);
        
        k--; //тк индексы с 0
        
        for (int i = 0; i < n; i++) {
			
            int t = 0;
            
            if (k != 0) {
				      f /= (n - i);
				      t = k / f;
				      k = k % f;
			      }
            
			s[i] = (char)(((int)'0') + perest[t]);
            perest.erase(perest.begin() + t);
		}
        
		return s;
        
    }
};
