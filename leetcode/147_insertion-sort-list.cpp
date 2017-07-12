//Sort a linked list using insertion sort.

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
class Solution_147 {
public:
    // 2 Pointers (My own)
    // Time:	O(n)
    // Space:	O(n^2)
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *node(head), *pre(dummy);
        while (node->next) {
            pre = dummy;
            while (pre != node && pre->next->val <= node->next->val)
                pre = pre->next;
            if (pre->next->val > node->next->val) {
                ListNode* tmp = pre->next;
                pre->next = node->next;
                node->next = node->next->next;
                pre->next->next = tmp;
            } else
                node = node->next;
        }
        return dummy->next;
    }
};



//int main() {
//    Solution_147 sol;
//    ListNode* head = new ListNode(3);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(1);
//    ListNode* result(sol.insertionSortList(head));
//    while (result) {
//        cout << result->val << "\t";
//        result = result->next;
//    }
//}