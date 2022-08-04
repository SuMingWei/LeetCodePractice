// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pos = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != pos){
                    slow = slow->next;
                    pos = pos->next;
                }
                return pos;
            }
        }
        return NULL;
    }
};