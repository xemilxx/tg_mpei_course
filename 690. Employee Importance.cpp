// https://leetcode.com/problems/employee-importance/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
         
        map<int, Employee*> m;
        
        for (int i = 0; i < employees.size() ; i++) {
            m[employees[i]->id] = employees[i];
        }
        
        int res = 0;
        queue<Employee*> q;
        q.push(m[id]);
        
        while (!q.empty()) {
            
            auto e = q.front();
            q.pop();
            res += e->importance;
            for (auto sub : e->subordinates){
                q.push(m[sub]);
            }
            
        }
        
        return res;
       
    }
};
