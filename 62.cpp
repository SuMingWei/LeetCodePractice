// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long a = m+n-2, b, res1=1,res2=1;
        b = min(m-1,n-1);
        for(int i=0;i<b;i++){
            res1 *= (a-i);
            res2 *= (b-i);
            if(res1 % res2 == 0){
                res1 /= res2;
                res2 = 1;
            }
        }
        return res1/res2;
    }
};