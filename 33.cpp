// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target < nums[mid]) r = mid-1;
                else l = mid + 1;
            }else{
                if(target > nums[mid] && target <= nums[r]) l = mid+1;
                else r = mid - 1;
            }
        }
        return -1;   
    }
};