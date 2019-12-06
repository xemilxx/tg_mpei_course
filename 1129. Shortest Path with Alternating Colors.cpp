//https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        vector<vector<pair<int, int>>> gr(n);
        for (auto red : red_edges) {
            gr[red[0]].push_back({red[1], 0});
        }
        for (auto blue : blue_edges) {
            gr[blue[0]].push_back({blue[1], 1});
        }
        
        vector<vector<bool>> visited(n, vector(2, false));
        queue<pair<int, int>> q;
        vector<int> res(n, -1);
        
        q.push({0, -1});
        int cur_len = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                pair<int, int> cur = q.front();
                q.pop();
                if (res[cur.first] == -1)
                    res[cur.first] = cur_len;
                for (auto g : gr[cur.first]) {
                    if (g.second != cur.second && !visited[g.first][g.second]) {
                        visited[g.first][g.second] = true;
                        q.push(g);
                    }
                }
            }
            cur_len++;
        }
        
        return res;    
    }
};
