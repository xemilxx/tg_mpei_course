//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    
     bool check(const string& a, const string& b) {
        bool flag = false;
        for (int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                if (!flag) flag = true;
                else return false;
            }
        }
        return true;
    }   
       
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> dist;
        unordered_map<string, bool> visited;
        queue<string> q;
        
        wordList.insert(wordList.begin(), beginWord);
        
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (check(wordList[i], wordList[j])) {
                    graph[wordList[j]].push_back(wordList[i]);
                    graph[wordList[i]].push_back(wordList[j]);
                }
            }
            visited[wordList[i]] = false;
        }
        
        q.push(beginWord);
        visited[beginWord] = true;
        dist[beginWord] = 1;
        
        while (!q.empty()) {
            
            string currWord = q.front();
            q.pop();
            
            if (currWord == endWord) return dist[currWord];
            
            for (auto word : graph[currWord]) {
                if (!visited[word]) {
                    q.push(word);
                    dist[word] = dist[currWord] + 1;
                    visited[word] = true;
                }
            }
        }    
        return 0;
    }   
};
