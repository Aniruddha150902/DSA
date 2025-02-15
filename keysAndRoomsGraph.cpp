// Keys and Rooms

// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

// Example 1:

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.
// Example 2:

// Input: rooms = [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.


//OWN SOLUCTION = 100% Time 97.24% space

// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         stack<int> st;
//         vector<bool> visited(n);
//         st.push(0);
//         visited[0] = true;
//         while(!st.empty()) {
//             int node = st.top();
//             st.pop();
//             for(int i=0;i<rooms[node].size();i++) {
//                 int temp = rooms[node][i];
//                 if(visited[temp])
//                     continue;
//                 st.push(temp);
//                 visited[temp] = true;
//             }
//         }
//         return all_of(visited.begin(),visited.end(),[](int i) {
//             return i == 1;
//         });
//     }
// };


//DFS

// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         stack<int> st;
//         unordered_set<int> visited = {0};
//         st.push(0);
//         while(!st.empty()) {
//             int i = st.top();
//             st.pop();
//             for(int j : rooms[i])
//                 if(visited.count(j) == 0) {
//                     st.push(j);
//                     visited.insert(j);
//                     if(visited.size() == n)
//                         return true;
//                 }
//         }
//         return visited.size() == n;
//     }
// };


//BFS

// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         queue<int> bfs;
//         unordered_set<int> visited;
//         bfs.push(0);
//         while(!bfs.empty()) {
//             int i = bfs.front();
//             bfs.pop();
//             visited.insert(i);
//             if(visited.size() == n)
//                 return true;
//             for(int j : rooms[i])
//                 if(visited.count(j) == 0)
//                     bfs.push(j);
//         }
//         return visited.size() == n;
//     }
// };


//DFS Recurrsive Time More
// class Solution {
// public:
//     void dfs(vector<vector<int>>& rooms, unordered_set<int>& v, int curr) {
//         if(v.count(curr) != 0)
//             return;
//         v.insert(curr);
//         for(int i : rooms[curr])
//             dfs(rooms,v,i);
//     }
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         unordered_set<int> v;
//         dfs(rooms, v , 0);
//         return v.size() == rooms.size();
//     }
// };


//DFS Recurrsive Space More 
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, unordered_set<int>& v, unordered_set<int>& keys, int curr) {
        v.insert(curr);
        for(int i : rooms[curr])
            keys.insert(i);
        for(int k: keys) 
            if(v.count(k) == 0)
                dfs(rooms, v, keys, k);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> v,keys;
        dfs(rooms, v, keys, 0);
        return v.size() == rooms.size();
    }
};
