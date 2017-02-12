//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include <iostream>
#include <vector>
#include <queue>

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
class Solution_021 {
public:
    //
    // Time:	O(n)
    // Space:	O(1)
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (l1 || l2) {
            int a = l1 ? l1->val : INT_MAX;
            int b = l2 ? l2->val : INT_MAX;
            if (a < b) {
                p = p->next = l1;
                l1 = l1->next;
            } else {
                p = p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy->next;
    }
};