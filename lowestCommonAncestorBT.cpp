// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [1,2], p = 1, q = 2
// Output: 1



// MY OWN SOLUTION
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool helper(TreeNode* root,TreeNode* p, TreeNode* q) {
//         if(!root)
//             return false;
//         if(root == p || root == q)
//             return true;
//         return helper(root->left,p,q) || helper(root->right,p,q);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root || root == p || root == q)
//             return root;
//         bool left = helper(root->left,p,q);
//         bool right = helper(root->right,p,q);
//         if(left && right) 
//             return root;
//         else if(left)
//             return lowestCommonAncestor(root->left, p, q);
//         else 
//             return lowestCommonAncestor(root->right,p,q);
//     }
// };



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        return !left ? right : !right ? left : root; 
    }
};
