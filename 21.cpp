// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return list1;
        if(list1 == nullptr && list2 != nullptr) return list2;
        if(list1 != nullptr && list2 == nullptr) return list1;
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        // init list
        if(list1->val < list2->val){
            ans->val = list1->val;
            list1 = list1->next;
            if(list1 == nullptr){
                ans->next = list2;
                return ans;
            }
        }else{
            ans->val = list2->val;
            list2 = list2->next;
            if(list2 == nullptr){
                ans->next = list1;
                return ans;
            }
        }   
        // append node
        while(1){
            ListNode* tmp = new ListNode();
            if(list1->val < list2->val){
                tmp->val = list1->val;
                list1 = list1->next;
            }else{
                tmp->val = list2->val;
                list2 = list2->next;
            }
            cur->next = tmp;
            cur = cur->next;
            if(list1 == nullptr && list2 != nullptr){
                cur->next = list2;
                break;
            } 
            if(list1 != nullptr && list2 == nullptr){
                cur->next = list1;
                break;
            }
        }
        return ans;      
    }
};