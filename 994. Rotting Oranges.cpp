// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
      int orangesRotting(vector<vector<int>>& grid) {
          
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        int sum = 0;
        queue<pair<int, int>> rot;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) 
                    sum++;
                else if (grid[i][j] == 2) 
                    rot.push({i, j});
            }
        }
        
        vector<vector<int>> steps = {{0, 1}, 
                                     {0, -1}, 
                                     {1, 0}, 
                                     {-1, 0}};
        
          while (!rot.empty()) {
            int size = rot.size();
            while (size--) {
                pair<int, int> p = rot.front(); 
                rot.pop();
                for (auto step : steps) {
                    if (p.first + step[0] >= 0 && p.first + step[0] < m && 
                      p.second + step[1] >= 0 && p.second + step[1] < n) {
                        if (grid[p.first + step[0]][p.second + step[1]] == 1) {
                            grid[p.first + step[0]][p.second + step[1]] = 2;
                            sum--;
                            rot.push({p.first + step[0], p.second + step[1]});
                        }
                    }
                }
            }
            
            if (!rot.empty()) 
                res++;
        }
        
        return sum == 0 ? res : -1;
    }
};
