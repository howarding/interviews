//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up:
//What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//Example:
//
//    Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 8 -> 0 -> 7

#include <iostream>
#include <stack>

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
class Solution_445 {
public:
    // Stack
    // Exp: https://discuss.leetcode.com/topic/65306/java-o-n-recursive-solution-by-counting-the-difference-of-length
    // Time:	O(n)
    // Space:	O(n)
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n1 = 0, n2 = 0;
        ListNode *p1 = l1, *p2 = l2;
        stack<int> sta;
        while (p1) {
            n1++;
            p1 = p1->next;
        }
        while (p2) {
            n2++;
            p2 = p2->next;
        }
        int diff = n1 - n2;
        if (diff < 0) return addTwoNumbers(l2, l1);
        while (diff) {
            sta.push(l1->val);
            l1 = l1->next;
            diff--;
        }
        while (l1) {
            sta.push(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *tail = NULL;
        while (!sta.empty()) {
            int val = sta.top();
            sta.pop();
            ListNode *p = new ListNode((val + carry) % 10);
            carry = (val + carry) / 10;
            p->next = tail;
            tail = p;
        }
        if (carry) {
            ListNode *p = new ListNode(carry);
            p->next = tail;
            tail = p;
        }
        return tail;
    }
};