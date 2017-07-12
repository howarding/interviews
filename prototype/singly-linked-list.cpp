
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    if (!head) return nullptr;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *mid(dummy), *end(dummy);
    // mid = (node_num + 1) / 2
    // end stops at the end node.
    while (end->next) {
        mid = mid->next;
        end = end->next;
        if (end->next) end = end->next;
    }
    return mid;
}