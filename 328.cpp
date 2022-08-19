// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd;
        ListNode* even;
        ListNode* head2;
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        if(head->next->next == NULL) return head;
        odd = head;
        even = head->next;
        head2 = even;
        
        while(1){
            // odd link
            odd->next = even->next;
            odd = odd->next;    
            // even link
            even->next = odd->next;
            even = even->next;              
            
            if(even == NULL || even->next == NULL) break;
        }
        odd->next = head2;
        return head;
    }
};