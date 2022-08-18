// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int num = 1;
        while(cur->next != NULL){
            num++;
            cur = cur->next;
        }
        if(num - n == 0){
            head = head->next;
        }else{
            cur = head;
            for(int i=1;i<num-n;i++){
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        return head;
    }
};