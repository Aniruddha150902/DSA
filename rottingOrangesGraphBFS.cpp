// 994. Rotting Oranges
// Solved
// Medium
// Topics
// Companies
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), freshCount = 0, minPassed = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> offsets = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    freshCount++;

        while(freshCount && !q.empty()) {
            int nq = q.size();
            for( int i = 0; i < nq; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for ( int j = 0; j < 4; j++) {
                    int a = x + offsets[j][0];
                    int b = y + offsets[j][1];

                    if(a < 0 || b < 0 || a >= m || b >= n || grid[a][b] == 0 || grid[a][b] == 2)
                        continue;

                    freshCount--;
                    grid[a][b] = 2;
                    q.push({a, b});
                }
            }
            minPassed++;
        }
        
        return freshCount ? -1 : minPassed;
    }
};
