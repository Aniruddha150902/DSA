// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true

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
//     void leafSequence(TreeNode* root, vector<int>& ls) {
//         if(root) {
//             leafSequence(root->left,ls);
//             leafSequence(root->right,ls);
//             if(!root->left && !root->right) 
//                 ls.push_back(root->val);
//         }

//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         vector<int> ls1,ls2;
//         leafSequence(root1,ls1);
//         leafSequence(root2,ls2);
//         return ls1==ls2;
//     }
// };


// class Solution {
// public:
//     void leafSequence(TreeNode* root, string& ls) {
//         if(root) {
//             leafSequence(root->left,ls);
//             leafSequence(root->right,ls);
//             if(!root->left && !root->right) 
//                 ls += to_string(root->val) + '#';
//         }

//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         string ls1,ls2;
//         leafSequence(root1,ls1);
//         leafSequence(root2,ls2);
//         return ls1==ls2;
//     }
// };


class Solution {
public:
    int dfs(stack<TreeNode*>& ls) {
        while(true) {
            TreeNode *temp = ls.top();
            ls.pop();
            if(temp->left)
                ls.push(temp->left);
            if(temp->right)
                ls.push(temp->right);
            if(!temp->left && !temp->right) 
                return temp->val;
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> ls1,ls2;
        ls1.push(root1);
        ls2.push(root2);
        while(!ls1.empty() && ! ls2.empty())
            if(dfs(ls1) != dfs(ls2)) 
                return false;
        return ls1.empty() && ls2.empty();
    }
};
