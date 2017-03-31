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
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> old2new;
        RandomListNode *dummy = new RandomListNode(-1);
        RandomListNode *tmp = head;
        RandomListNode *curr = dummy;
        while (tmp) {
            RandomListNode *newNode = new RandomListNode(tmp->label);
            old2new[tmp] = newNode;
            curr->next = newNode;
            curr = curr->next;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            if (tmp->random) {
                old2new[tmp]->random = old2new[tmp->random];
            }
            tmp = tmp->next;
        }
        return dummy->next;
    }
};