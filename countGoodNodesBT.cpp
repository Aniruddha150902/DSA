// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.

// Example 1:

// Input: root = [3,1,4,3,null,1,5]
// Output: 4
// Explanation: Nodes in blue are good.
// Root Node (3) is always a good node.
// Node 4 -> (3,4) is the maximum value in the path starting from the root.
// Node 5 -> (3,4,5) is the maximum value in the path
// Node 3 -> (3,1,3) is the maximum value in the path.


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
//     int inorder(TreeNode* root,int maxi) {
//         if(!root)
//             return 0;
//         int count = root->val >= maxi ? 1 : 0;
//         count += inorder(root->left,max(maxi,root->val));
//         count += inorder(root->right,max(maxi,root->val));
//         return count;
//     }
//     int goodNodes(TreeNode* root) {
//         return inorder(root,INT_MIN);
//     }
// };



class Solution {
public:
    int goodNodes(TreeNode* root, int maxi = INT_MIN) {
        return root ? (root->val >= maxi ? 1 : 0) + goodNodes(root->left,max(maxi,root->val)) + goodNodes(root->right,max(maxi,root->val)) : 0;
    }
};
