// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

// Example 1:


// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6. 



//Find the Middle of the SLL and then Reverse the Second Half

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         ListNode *slow=head,*fast=head;
//         while(fast) {
//             slow=slow->next;
//             fast=fast->next->next;
//         }

//         fast=nullptr;
//         while(slow) {
//             ListNode *nextNode=slow->next;
//             slow->next=fast;
//             fast=slow;
//             slow=nextNode;
//         }

//         int maxi=INT_MIN;
//         while(fast) {
//             maxi=max(maxi,head->val + fast->val);
//             head=head->next;
//             fast=fast->next;
//         }

//         return maxi;
//     }
// };


//Reverse the First Half Simultaneously Finding the middle of the SLL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast=head,*prev=nullptr;
        while(fast) {
            fast=fast->next->next;
            ListNode *nextNode = head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
        }

        int maxi=INT_MIN;
        while(prev) {
            maxi=max(maxi,prev->val + head->val);
            prev=prev->next;
            head=head->next;
        }

        return maxi;
    }
};
