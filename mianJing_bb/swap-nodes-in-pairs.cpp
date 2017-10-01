//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

#include <iostream>
#include <vector>

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* node = dummy;
        while (node->next && node->next->next) {
            ListNode* tmp = node->next->next;
            node->next->next = tmp->next;
            tmp->next = node->next;
            node->next = tmp;
            node = node->next->next;
        }
        return dummy->next;
    }
};