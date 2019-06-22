//Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
//
//Follow up:
//What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
//
//Example:
//
//    // Init a singly linked list [1,2,3].
//    ListNode head = new ListNode(1);
//    head.next = new ListNode(2);
//    head.next.next = new ListNode(3);
//    Solution solution = new Solution(head);
//
//    // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
//    solution.getRandom();
//    Hide Company Tags

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
class Solution_382 {
    ListNode *root;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    // Exp: https://en.wikipedia.org/wiki/Reservoir_sampling
    // Exp: https://discuss.leetcode.com/topic/55049/java-solution-with-cases-explain
    // Time:	O(n)
    // Space:	O(1)
    Solution_382(ListNode *head) {
        root = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int result, i = 1;
        for (ListNode* p = root; p; p = p->next)
            if (rand() % i++ == 0)
                result = p->val;
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */