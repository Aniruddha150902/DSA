// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:

// Input: root = [1,2,3,null,5,null,4]

// Output: [1,3,4]

// Explanation:



// Example 2:

// Input: root = [1,2,3,4,null,null,null,5]

// Output: [1,3,4,5]

// Explanation:



// Example 3:

// Input: root = [1,null,3]

// Output: [1,3]

// Example 4:

// Input: root = []

// Output: []




//BFS

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
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root) 
//             return {};
//         queue<TreeNode*> q;
//         int n=0;
//         vector<int> res;
//         q.push(root);
//         while(!q.empty()) {
//             n=q.size();
//             for(int i=0;i<n;i++) {
//                 TreeNode *t = q.front();
//                 q.pop();
//                 if(t->left)                
//                     q.push(t->left);
//                 if(t->right)
//                     q.push(t->right);
//                 if(i==n-1)
//                     res.push_back(t->val);  
//             }
//         }
//         return res;
//     }
// };




//DFS

class Solution {
public:
    void rightView(TreeNode* curr, int level, vector<int>& res) {
        if(!curr)
            return;
        if(res.size() == level) 
            res.push_back(curr->val);
        rightView(curr->right, level+1, res);
        rightView(curr->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightView(root,0,res);
        return res;
    }
};
