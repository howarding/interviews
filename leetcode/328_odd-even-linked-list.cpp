//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note:
//The relative order inside both the even and odd groups should remain as it was in the input.
//The first node is considered odd, the second node even and so on ...

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
class Solution {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* oddDummy = new ListNode(-1);
        ListNode* evenDummy = new ListNode(-1);
        ListNode *node = head, *odd = oddDummy, *even = evenDummy;
        while (node) {
            odd = odd->next = node;
            even = even->next = node->next;
            node = node->next ? node->next->next : node->next;
        }
        odd->next = evenDummy->next;
        return oddDummy->next;
    }
};