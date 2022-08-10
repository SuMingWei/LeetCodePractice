// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int cnt[46];
        cnt[1] = 1, cnt[2] = 2;
        for(int i=3;i<46;i++){
            cnt[i] = cnt[i-1]+cnt[i-2];
        }
        
        // from stair:n-1 climb 1 stair + from stair:n-2 climb 2 stairs;
        return cnt[n];
    }
};