// Delete Node in a BST
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
// Example 3:

// Input: root = [], key = 0
// Output: []

//ITERATIVE SOLUTION  ==== I HAVE POSTED THE BELOW SOLUTION ON LEETCODE - LINK - https://leetcode.com/problems/delete-node-in-a-bst/solutions/6394094/simple-intuitive-and-iterative-solution-for-deleting-a-node-in-a-binary-search-tree-c

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
//     TreeNode* helper(TreeNode* curr) {
//         if(!curr->left)
//             return curr->right;
//         if(!curr->right)
//             return curr->left;
//         TreeNode *t = curr->left;
//         while(t->right)
//             t = t->right;
//         t->right = curr->right;
//         return curr->left;
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(!root)
//             return nullptr;
//         TreeNode *t=root,*p=nullptr;
//         while(t && t->val != key) {
//             p = t;
//             t = t->val > key ? t->left : t->right;
//         }
//         if(!t)
//             return root;
//         TreeNode *s = helper(t);
//         if(!p)
//             return s;
//         if(p->val > t->val)
//             p->left = s;
//         else 
//             p->right = s;
//         return root;
//     }
// };



// RECURRSIVE 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;
            TreeNode *t = root->left;
            while(t->right)
                t = t->right;
            root->val = t->val;
            root->left = deleteNode(root->left, t->val);
        }
        return root;
    }
};
