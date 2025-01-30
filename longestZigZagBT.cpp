// You are given the root of a binary tree.

// A ZigZag path for a binary tree is defined as follow:

// Choose any node in the binary tree and a direction (right or left).
// If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
// Change the direction from right to left or from left to right.
// Repeat the second and third steps until you can't move in the tree.
// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

// Return the longest ZigZag path contained in that tree.

 

// Example 1:


// Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
// Output: 3
// Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
// Example 2:


// Input: root = [1,1,1,null,1,null,null,1,1,null,1]
// Output: 4
// Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
// Example 3:

// Input: root = [1]
// Output: 0



// My Own Solution -


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
// class Solution {
// public:
//     int calc(TreeNode* root,int count, int dir) {
//         if(!root)
//             return count;
//         count++;
//         count = dir ? calc(root->right, count, 0) : calc(root->left, count, 1); 
//         return count;
//     }
//     int dfs(TreeNode* root, int maxi) {
//         if(!root) 
//             return maxi;
//         int nodeMax = max(calc(root, 0, 0), calc(root, 0, 1));
//         maxi = max(maxi,nodeMax);
//         maxi = max(maxi,dfs(root->left, maxi));
//         maxi = max(maxi,dfs(root->right, maxi));
//         return maxi;
//     }
//     int longestZigZag(TreeNode* root) {
//         return dfs(root, 0) - 1;
//     }
// };



// class Solution {
// public:
//     int maxi = 0;
//     void dfs(TreeNode* root, bool isLeft, int step) {
//         if(!root) 
//             return;
//         maxi = max(maxi, step);
//         if(isLeft) {
//             dfs(root->left, false, step+1);
//             dfs(root->right, true, 1);
//         } else {
//             dfs(root->right, true, step+1);
//             dfs(root->left, false, 1);
//         }
//     }

//     int longestZigZag(TreeNode* root) {
//         dfs(root,true,0);
//         return maxi;
//     }
// };



class Solution {
public:
    void ziggy(TreeNode* root, int l, int r, int& ans) {
        if(!root)
            return;
        ans = l ? max(ans, l) : max(ans, r);
        ziggy(root->left, 0, l+1, ans);
        ziggy(root->right, r+1, 0, ans);
    }
    int longestZigZag(TreeNode* root) {
        int l=0,r=0,ans=0;
        ziggy(root, l, r, ans);
        return ans;
    }
};
