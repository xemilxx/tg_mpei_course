//https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        
        int s1 = num1.size();
        int s2 = num2.size();
        
        vector<int> val(s1 + s2);
        
        for (int i = s1 - 1; i >= 0; --i) {
            for (int j = s2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = val[i + j + 1] + mul;
                val[i + j + 1] = sum % 10;
                val[i + j] += sum / 10;
            }
        }
        
        string num3 = "";
        for (auto i : val) {
            if (!(i == 0 && num3.size() == 0)) {
                num3.push_back(i + '0');
            }
        }
        
        return num3 == "" ? "0" : num3;
            
    }
};
