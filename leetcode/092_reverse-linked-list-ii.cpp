//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ? m ? n ? length of list.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_092 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n) return head;
        int count = 0;
        ListNode* dummy = new ListNode(-1), *start = dummy;
        dummy->next = head;
        while (start->next && ++count < m) start = start->next;
        if (!start->next) return head;
        ListNode* pre = nullptr, *end = start->next;
        while (end && count++ <= n) {
            ListNode* tmp = end->next;
            end->next = pre;
            pre = end;
            end = tmp;
        }
        start->next->next = end;
        start->next = pre;
        return dummy->next;
    }
};


//int main() {
//    Solution_092 sol;
//    ListNode* head = new ListNode(3);
//    head->next = new ListNode(5);
//    int m = 1, n = 2;
//    ListNode* result(sol.reverseBetween(head, m, n));
//}