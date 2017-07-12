//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

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
class Solution_086 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *low = new ListNode(0);
        ListNode *result_low = low;
        ListNode *high = new ListNode(0);
        ListNode *result_high = high;
        for(; head; head = head->next){
            if(head->val < x)
                low = low->next = head;
            else
                high = high->next = head;
        }
        high->next = nullptr;
        low->next = result_high->next;
        return result_low->next;
    }
};