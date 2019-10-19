//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    int DFS(vector<vector<char>>& grid, int i, int j) {
        
        if (j < 0 || j >= grid[0].size() || i < 0 || i >= grid.size() || grid[i][j] == '0')
        {
            return 0;
        }
        
        grid[i][j] = '0';
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        
        return 1;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size() == 0) {
            return 0;
        }
        
        int num = 0;
        int s = grid.size();        
        for (int i = 0; i < s; i++) {
            int s2 = grid[0].size();
            for (int j = 0; j < s2; j++) {
                if (grid[i][j] == '1') {
                    num += DFS(grid, i, j);
                }
            }
        }
        
        return num;
    
    }
    
};
