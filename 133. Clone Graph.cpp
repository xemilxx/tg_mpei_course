//https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (node == NULL) return NULL;
        
        unordered_map<Node*, Node*> copy;
        
        queue<Node*> q({node});
        copy[node] = new Node(node->val);
        
        while (!q.empty()) {   
            Node* cur = q.front();
            q.pop();
            
            for (auto nb : cur->neighbors) {
                if (copy.count(nb)) {
                    copy[cur]->neighbors.push_back(copy[nb]);
                } else {
                    copy[nb] = new Node(nb->val);
                    copy[cur]->neighbors.push_back(copy[nb]);
                    q.push(nb);
                }
            }   
        }
        return copy[node];  
    }
};
