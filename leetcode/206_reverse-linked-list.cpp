//Reverse a singly linked list.
//
//click to show more hints.
//
//Hint:
//A linked list can be reversed either iteratively or recursively. Could you implement both?

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
class Solution_206 {
public:
    // Exp: https://discuss.leetcode.com/topic/13268/in-place-iterative-and-recursive-java-solution

    // Iterative
    // Time:	O(n)
    // Space:	O(1)
    ListNode *reverseList(ListNode *head) {
        ListNode *p = nullptr;
        while (head) {
            // Need at least 3 pointers
            ListNode *tmp = head->next;
            head->next = p;
            p = head;
            head = tmp;
        }
        return p;
    }

    // Recursive
    // Time:	O(n)
    // Space:	O(1)
    ListNode *reverseList_1(ListNode *head) {
        return helper(nullptr, head);
    }

    ListNode *helper(ListNode *p, ListNode *q) {
        if (!q) return p;
        ListNode *tmp = q->next;
        q->next = p;
        return helper(q, tmp);
    }
};