//https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if (N == 1) {
            return 1;
        }
        
        int res = -1;
        
        vector<int> scores(N + 1, 0);
        
        for (const auto v : trust) {
            if (scores[v[0]]-- == N - 1) {
                res = -1;
            }
            if (scores[v[1]]++ == N - 2) {
                res = v[1];
            }
        }
        return res;
        
    }
};
