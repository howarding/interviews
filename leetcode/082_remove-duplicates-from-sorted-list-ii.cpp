//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

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
class Solution_082 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *p = result;
        bool duplicate = false;
        for(ListNode* q = p->next; q->next; q = q->next){
            if(q->val == q->next->val)
                duplicate = true;
            else if(duplicate){
                p->next = q->next;
                duplicate = false;
            }
            else
                p = p->next;
        }
        if(duplicate)
            p->next = nullptr;
        return result->next;
    }
};