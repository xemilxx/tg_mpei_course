//https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     
        vector<vector<int>> v;
        
        for (size_t i = 1; i <= numRows; i++) {
            
            vector<int> lvl(i, 1);
            
            for (size_t j = 1; j < i - 1; j++) {
                lvl[j] = v[i - 2][j - 1] + v[i - 2][j];
            }
            
            v.push_back(lvl);
            
        }
        
        return v;
        
    }
};
