// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int num = 0, mid;
        while(cur != nullptr){
            num++;
            cur = cur->next;
        }
        if(num % 2 == 1){
            mid = (num+1)/2;
        }else{
            mid = num/2 + 1;
        }
        for(int i=1;i<mid;i++){
            head = head->next;
        }
        return head;
    }
};