// Number of Provinces
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// class Solution {
// public:
//     void dfs(vector<vector<int>>& isConnected, vector<bool>& v, int curr) {
//         v[curr] = true;
//         for(int i = 0; i < isConnected.size(); i++)
//             if(isConnected[curr][i] && !v[i])
//                 dfs(isConnected, v, i);
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size(), count = 0;
//         vector<bool> v(n, false);
//         for(int i = 0; i < n; i++)
//             if(!v[i]) {
//                 count++;
//                 dfs(isConnected, v, i);
//             }
//         return count;
//     }
// };

// class Solution {
// public:
//     void dfs(vector<vector<int>>& isConnected, int curr) {
//         isConnected[curr][curr] = 0;
//         for(int i =  0; i < isConnected.size(); i++)
//             if(isConnected[curr][i] && isConnected[i][i]) {
//                 isConnected[curr][i] = isConnected[i][curr] = 0; // NOT REQUIRED
//                 dfs(isConnected, i);
//             }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size(), count = 0;
//         for(int i = 0; i < n; i++)
//             if(isConnected[i][i]) {
//                 count++;
//                 dfs(isConnected, i);
//             }
//         return count;
//     }
// };

// UNION FIND USING SIZE

// class DisJointSet {
//     int group;
//     vector<int> p, size;

// public:
//     DisJointSet(int n) {
//         group = n;
//         size.resize(n, 1);
//         p.resize(n);
//         for(int i = 0; i < n; i++)
//             p[i] = i;
//     }

//     int getGroup() {
//         return group;
//     }

//     int find(int a) {
//         if(a == p[a])
//             return a;
//         return p[a] = find(p[a]);
//     }

//     void Union(int a, int b) {
//         int roota = find(a);
//         int rootb = find(b);
//         if(roota == rootb)
//             return;
//         if(size[roota] < size[rootb]) {
//             p[roota] = rootb;
//             size[rootb] += size[roota];
//         } else {
//             p[rootb] = roota;
//             size[roota] += size[rootb];
//         }
//         group--;
//     }
// };

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         DisJointSet ds(n);
//         for(int i = 0; i < n-1; i++)
//             for(int j = i+1; j < n; j++)
//                 if(isConnected[i][j])
//                     ds.Union(i, j);
//         return ds.getGroup();
//     }
// };

class DisJointSet {
    int group;
    vector<int> p;

public:
    DisJointSet(int n) {
        group = n;
        p.resize(n);
        for(int i = 0; i < n; i++)
            p[i] = i;
    }

    int getGroup() {
        return group;
    }

    int find(int a) {
        if(a == p[a])
            return a;
        return p[a] = find(p[a]);
    }

    void Union(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        if(roota != rootb) {
            p[rootb] = roota;
            group--;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJointSet ds(n);
        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                if(isConnected[i][j])
                    ds.Union(i, j);
        return ds.getGroup();
    }
};
