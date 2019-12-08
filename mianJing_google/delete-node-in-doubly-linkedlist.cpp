//给一个target value，在doubly linkedlist 中删除一个节点
//follow up: 如果允许有重复，删除全部重复节点怎么处理

#include <iostream>
using namespace std;

struct DoublyListNode {
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(int v): val(v), prev(NULL), next(NULL) {}
};

class DoublyList {
public:
    // https://www.geeksforgeeks.org/delete-occurrences-given-key-doubly-linked-list/
    // Time:    O(1)
    // Space:   O(1)
    void deleteNode(DoublyListNode* node) {
        if (!node) return;
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        free(node);
    }

    // Time:    O(1)
    // Space:   O(1)
    void deleteNode(DoublyListNode* head, DoublyListNode* node) {
        if (!head || !node) return;
        if (head == node)
            head = node->next;
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        free(node);
    }

    // Time:    O(n)
    // Space:   O(1)
    DoublyListNode* deleteValue(DoublyListNode* head, int val) {
        if (!head) return head;
        DoublyListNode* dummy = new DoublyListNode(-1);
        DoublyListNode* next;
        dummy->next = head;
        while (head) {
            next = head->next;
            if (head->val == val) {
                if (head->next)
                    head->next->prev = head->prev;
                if (head->prev)
                    head->prev->next = head->next;
                free(head);
            }
            head = next;
        }
        return dummy->next;
    }
};