//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

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
    // My own
    // Time:	O(n)
    // Space:	O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        int len = 1;
        ListNode *p = head;
        while(p -> next){
            p = p -> next;
            len++;
        }
        k = len - k % len;
        if(k == len) return head;
        p -> next = head;

        for(int i = 0; i < k; i++)
            p = p -> next;
        head = p -> next;
        p -> next = nullptr;
        return head;
    }
};