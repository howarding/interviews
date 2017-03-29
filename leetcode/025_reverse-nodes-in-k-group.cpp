//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

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
    // Reverse group by group
    // Time:	O(n)
    // Space:	O(1)
    ListNode *reverseKGroup(ListNode *head, int k) {
        int count = 0;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        while (head) {
            head = head->next;
            count++;
        }
        int n = count / k;
        head = dummy->next;
        ListNode *pre = nullptr, *group_pre = dummy, *end;
        for (int i = 0; i < n; i++) {
            end = head;
            for (int j = 0; j < k; j++) {
                ListNode *tmp = head->next;
                head->next = pre;
                pre = head;
                head = tmp;
            }
            group_pre->next = pre;
            end->next = head;
            group_pre = end;
        }
        return dummy->next;
    }
};