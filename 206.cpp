// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        // null list or only one
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* tail = head;
        ListNode* cur = head->next;
        while(cur != nullptr){
            tail->next = cur->next;
            cur->next = head;
            head = cur;
            cur = tail->next; 
        }
        return head;
    }
};