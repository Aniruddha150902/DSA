// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// ITERATIVE
// BFS

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) 
//             return 0;
//         int res=0;
//         queue<TreeNode*> bfs;
//         bfs.push(root);
//         while(!bfs.empty()) {
//             res++;
//             for(int i=0,n=bfs.size();i<n;i++) {
//                 TreeNode *node=bfs.front();
//                 bfs.pop();
//                 if(node->left)
//                     bfs.push(node->left);
//                 if(node->right)
//                     bfs.push(node->right);
//             }
//         }
//         return res;
//     }
// };

//DFS
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) 
//             return 0;
//         int maxi=0;
//         stack<pair<TreeNode*,int>> st;
//         st.push({root,1});
//         while(!st.empty()) {
//             auto [node, count] = st.top();
//             maxi=max(maxi,count);
//             st.pop();
//             if(node->left)
//                 st.push({node->left,count+1});
//             if(node->right)
//                 st.push({node->right,count+1});
//         }
//         return maxi;
//     }
// };


// Recursive
class Solution {
public:
    int maxDepth(TreeNode* root) {
         if(!root) 
            return 0;
        return max(maxDepth(root->right),maxDepth(root->left)) + 1;
    }
};
