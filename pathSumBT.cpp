Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3


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
// private: 
//     int noOfPaths = 0;
// public:
//     void dfs(TreeNode* root,long long targetSum) {
//         if(!root)
//             return;
//         long long req = targetSum - root->val;
//         if(req == 0)
//             noOfPaths++;
//         dfs(root->left,req);
//         dfs(root->right,req);
//     }
//     void preOrder(TreeNode* root, int targetSum) {
//         if(!root)
//             return;
//         dfs(root,targetSum);
//         preOrder(root->left,targetSum);
//         preOrder(root->right,targetSum);
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         preOrder(root,targetSum);
//         return noOfPaths;
//     }
// };

class Solution {
public:
    int dfs(TreeNode* root,long long int currSum, long long targetSum, unordered_map<long long,int>& cache) {
        if(!root)
            return 0;
        currSum += root->val;
        int res = cache[currSum - targetSum];
        cache[currSum]++;
        res += dfs(root->left,currSum,targetSum,cache) + dfs(root->right,currSum,targetSum,cache);
        cache[currSum]--;
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> cache;
        cache[0]++;
        return dfs(root,0,targetSum,cache);
    }
};
