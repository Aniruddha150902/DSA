// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.

 

// Example 1:


// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// Output: 3
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
// Example 2:


// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// Output: 2
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
// Example 3:

// Input: n = 3, connections = [[1,0],[2,0]]
// Output: 0
 

// class Solution {
// public:
//     int dfs(unordered_map<int, unordered_set<int>>& in, unordered_map<int, unordered_set<int>>& out, int from) {
//         int count = 0;

//         for(int x : out[from]) {
//             count++;
//             in[x].erase(from);
//             count += dfs(in, out, x);
//         }

//         for(int x : in[from]) {
//             out[x].erase(from);
//             count += dfs(in, out, x);
//         }

//         return count;
//     }
//     int minReorder(int n, vector<vector<int>>& connections) {
//         unordered_map<int, unordered_set<int>> in(n), out(n);

//         for(auto conn : connections) {
//             out[conn[0]].insert(conn[1]);
//             in[conn[1]].insert(conn[0]);
//         }

//         return dfs(in, out, 0);
//     }
// };


class Solution {
public:
    int dfs(vector<vector<int>>& adj, int prev, int from) {
        return accumulate(adj[from].begin(), adj[from].end(), 0, [&](int sum, int to) -> int {
            return sum + (abs(to) == prev ? 0 : (dfs(adj, from, abs(to)) + (to > 0)));
        });
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto &conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(-conn[0]);
        }

        return dfs(adj, 0, 0);
    }
};
