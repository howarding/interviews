//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution_138 {
public:
    // 1 pass!!!    Faster
    // Exp: https://segmentfault.com/a/1190000009675203
    // Time:	O(n)
    // Space:	O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> dict;
        RandomListNode *dummy = new RandomListNode(-1);
        RandomListNode *node = head;
        RandomListNode *curr = dummy;
        while (node) {
            if (dict.find(node) == dict.end())
                dict[node] = new RandomListNode(node->label);
            curr = curr->next = dict[node];
            if (node->random) {
                if (dict.find(node->random) == dict.end())
                    dict[node->random] = new RandomListNode(node->random->label);
                curr->random = dict[node->random];
            }
            node = node->next;
        }
        return dummy->next;
    }


    // 2 passes
    // Time:	O(n)
    // Space:	O(1)
    RandomListNode *copyRandomList1(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> dict;
        RandomListNode *dummy = new RandomListNode(-1);
        RandomListNode *node = head;
        RandomListNode *curr = dummy;
        while (node) {
            dict[node] = new RandomListNode(node->label);
            curr = curr->next = dict[node];
            node = node->next;
        }

        node = head;
        while (node) {
            if (node->random) {
                dict[node]->random = dict[node->random];
            }
            node = node->next;
        }
        return dummy->next;
    }
};