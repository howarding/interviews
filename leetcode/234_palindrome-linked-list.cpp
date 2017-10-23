//Given a singly linked list, determine if it is a palindrome.
//
//Follow up:
//Could you do it in O(n) time and O(1) space?

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
class Solution_234 {
public:
    // 2Pointers,   reverse half list
    // Exp: https://discuss.leetcode.com/topic/18304/share-my-c-solution-o-n-time-and-o-1-memory
    // Time:	O(n)
    // Space:	O(1)
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != NULL) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (!head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }



    // 2Pointers,   Stack
    // Time:	O(n)
    // Space:	O(n)
    bool isPalindrome1(ListNode *head) {
        if (!head || !head->next) return true;
        stack<int> stk;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            stk.push(slow->val);
        }
        slow = fast->next ? slow->next->next : slow->next;
        while (!stk.empty()) {
            if (stk.top() != slow->val) return false;
            stk.pop();
            slow = slow->next;
        }
        return true;
    }
};


//int main() {
//    ListNode* head = new ListNode(1);
//    ListNode* dummy = head;
//    dummy->next = new ListNode(0);
//    dummy = dummy->next;
//    dummy->next = new ListNode(0);
//    Solution_234 sol;
//    cout << sol.isPalindrome(head) << endl;
//}