// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long mid=0, s=1, e=n;
        while(s <= e){
            if(s == e) return s;
            
            mid = (s+e)/2;
            if(isBadVersion(mid)) e = mid;
            else s = mid+1;
        }
        return mid;
    }
};