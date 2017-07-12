//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗
//B:     b1 → b2 → b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.
//Credits:
//Special thanks to @stellari for adding this problem and creating all test cases.

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
    // VERY SMART!!!
    // Exp: https://discuss.leetcode.com/topic/28067/java-solution-without-knowing-the-difference-in-len
    // Time:	O(n)
    // Space:	O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *nodeA(headA), *nodeB(headB);

        while (nodeA != nodeB) {
            nodeA = nodeA ? nodeA->next : headB;
            nodeB = nodeB ? nodeB->next : headA;
        }
        return nodeA;
    }




    // My own
    // Time:	O(n)
    // Space:	O(1)
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        ListNode *nodeA(headA), *nodeB(headB);
        int countA(0), countB(0);
        while (nodeA) {
            nodeA = nodeA->next;
            countA++;
        }
        while (nodeB) {
            nodeB = nodeB->next;
            countB++;
        }

        return countA > countB ?
               IntersectionNode(headA, headB, countA-countB) :
               IntersectionNode(headB, headA, countB-countA);
    }

    ListNode* IntersectionNode(ListNode* headA, ListNode* headB, int count) {
        while (count-- > 0) {
            headA = headA->next;
        }
        while(headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};