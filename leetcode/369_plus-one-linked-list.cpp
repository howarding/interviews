//Given a non-negative number represented as a singly linked list of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.
//
//Example:
//    Input:
//    1->2->3
//
//    Output:
//    1->2->4

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
class Solution_369 {
public:
    // Exp: https://discuss.leetcode.com/topic/49556/iterative-two-pointers-with-dummy-node-java-o-n-time-o-1-space
    // Time:	O(n)
    // Space:	O(1)
    ListNode *plusOne(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *lastNotNode = dummy, *node = head;
        while (node) {
            if (node->val != 9)
                lastNotNode = node;
            node = node->next;
        }
        lastNotNode->val++;
        node = lastNotNode->next;
        while (node) {
            node->val = 0;
            node = node->next;
        }
        return dummy->val ? dummy : head;
    }
};