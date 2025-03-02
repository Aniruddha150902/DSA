// https://leetcode.com/problems/evaluate-division/solutions/6486488/evaluate-division-graph-problem-c-dfs-bf-omx5

// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0
// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]



// class Solution {
// public:
//     double dfs(unordered_map<string, unordered_map<string, double>>& adj, string divisor, string dividend, vector<string> visited) {
//         visited.push_back(divisor);
//         if(adj.find(divisor) != adj.end())
//             if(adj[divisor].find(dividend) != adj[divisor].end())
//                 return adj[divisor][dividend];
//             else 
//                 for(auto& x : adj[divisor])
//                     if(find(visited.begin(), visited.end(), x.first) == visited.end()) {
//                         double prodWeight = dfs(adj, x.first, dividend, visited);
//                         if(prodWeight != -1.0)
//                             return x.second * prodWeight;
//                     }
//         return -1.0;
//     }
//     double bfs(unordered_map<string, unordered_map<string, double>>& adj, string divisor, string dividend, vector<string> visited) {
//         if(adj.find(divisor) == adj.end() || adj.find(dividend) == adj.end())
//             return -1.0;
//         queue<pair<string, double>> q;
//         q.push({divisor, 1.0});
//         while(!q.empty()) {
//             pair<string, double>& node = q.front();
//             if(node.first == dividend)
//                 return node.second;
//             visited.push_back(node.first);
//             for(auto& x : adj[node.first])
//                 if(find(visited.begin(), visited.end(), x.first ) == visited.end())
//                     q.push({x.first, x.second * node.second});
//             q.pop();
//         }
//         return -1.0;
//     }
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         unordered_map<string, unordered_map<string, double>> adj;
//         vector<double> res;

//         for(int i = 0; i < equations.size(); i++) {
//             string u = equations[i][0], v = equations[i][1];
//             double div = values[i];
//             adj[u].insert({v, div});
//             adj[v].insert({u, 1/div});
//         }

//         for(auto query : queries)  {
//             double val = bfs(adj, query[0], query[1], vector<string>());
//             if(val != -1) {
//                 adj[query[0]].insert({query[1], val});
//                 adj[query[1]].insert({query[0], 1/val});
//             }
//             res.push_back(val);
//         }
        
//         return res;
//     }
// };



class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        vector<double> res;

        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            double div = values[i];
            adj[u].insert({u, 1});
            adj[v].insert({v, 1});
            adj[u].insert({v, div});
            adj[v].insert({u, 1/div});
        }

        int n = adj.size();
        for(auto& k : adj)
            for(auto& i : adj[k.first])
                for(auto& j : adj[k.first])
                    if(adj[i.first].find(j.first) == adj[i.first].end()) {
                        double prodWeight = adj[i.first][k.first] * adj[k.first][j.first];
                        adj[i.first].insert({j.first, prodWeight});
                        adj[j.first].insert({i.first, 1/prodWeight});
                    }
        
        for_each(queries.begin(), queries.end(), [&adj, &res](auto& query) {
            double val = adj[query[0]][query[1]];
            res.push_back(val ? val : -1);
        });

        return res;
    }
};
