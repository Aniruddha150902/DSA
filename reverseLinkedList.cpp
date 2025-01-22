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

//Iterative

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head || !head->next)
//             return head;
//         ListNode *pre=nullptr,*nextNode;
//         while(head) {
//             nextNode=head->next;
//             head->next=pre;
//             pre=head;
//             head=nextNode;
//         }
//         return pre;
//     }
// };

//Recurrsive

// class Solution {
// public:
//     ListNode* reverseListRecursion(ListNode* pre,ListNode* curr) {
//         if(!curr)
//             return pre;
//         ListNode* nextNode = curr->next;
//         curr->next=pre;
//         return reverseListRecursion(curr,nextNode);
//     }
//     ListNode* reverseList(ListNode* head) {
//         if(!head || !head->next)
//             return head;
//         return reverseListRecursion(nullptr,head);
//     }
// };

class Solution {
public:
    ListNode* reverseListRecursion(ListNode* pre,ListNode* curr,ListNode* nextNode) {
        return curr ? reverseListRecursion(curr,curr->next,(curr->next=pre,nextNode)) : pre; //Comma Operator
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        return reverseListRecursion(nullptr,head,nullptr);
    }
};
