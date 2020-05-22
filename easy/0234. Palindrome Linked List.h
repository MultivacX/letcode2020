// 234. Palindrome Linked List

// Runtime: 28 ms, faster than 46.50% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 13.9 MB, less than 12.07% of C++ online submissions for Palindrome Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        auto slow = head;
        auto fast = head;
        while (true) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            if (!fast || !fast->next) break;
        }
        
        auto p = head;
        auto q = reverse(!fast ? slow : slow->next);
        while (q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        
        auto p = head->next;
        auto q = head;
        head->next = nullptr;
        while (p) {
            auto tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
        }
        return q;
    }
};