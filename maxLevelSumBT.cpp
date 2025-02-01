// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

// Example 1:


// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2


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
//     int maxLevelSum(TreeNode* root) {
//         if(!root)
//             return 0;
//         queue<TreeNode*> q;
//         int maxi=INT_MIN,maxl=-1;
//         q.push(root);
//         for(int level=1;!q.empty();++level) {
//             int sum = 0;
//             for(int i=q.size();i>0;--i) {
//                 TreeNode *t= q.front();
//                 q.pop();
//                 sum+=t->val;
//                 if(t->left)
//                     q.push(t->left);
//                 if(t->right)
//                     q.push(t->right);
//             }
//             if(sum > maxi) {
//                 maxi = sum;
//                 maxl = level;
//             }
//         }
//         return maxl;
//     }
// };



//DFS

class Solution {
public:
    void dfs(TreeNode* curr, int level, vector<int>& list) {
        if(!curr)
            return;
        if(level == list.size())
            list.push_back(curr->val);
        else
            list[level] += curr->val;
        dfs(curr->left,level+1,list);
        dfs(curr->right,level+1,list);
    }
    int maxLevelSum(TreeNode* root) {
       vector<int> list;
       dfs(root,0,list);
       return max_element(list.begin(),list.end()) - list.begin() + 1; 
    }
};
