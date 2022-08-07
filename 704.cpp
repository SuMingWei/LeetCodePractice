// 704. Binary Search
// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, s=0, e= nums.size()-1;
        while(s <= e){
            if(s == e){
                if(nums[s] == target) return s;
                else return -1;
            }
            mid = (s + e) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) s = mid + 1;
            else e = mid -1;
        }
        return -1;
    }
};