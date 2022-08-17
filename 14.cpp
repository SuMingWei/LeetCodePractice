// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 999;
        for(int i=0;i<strs.size();i++){
            minLen = min(minLen, int(strs[i].length()));
        }
        
        string ans = "";
        char cur;
        for(int i=0;i<minLen;i++){
            cur = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(cur != strs[j][i]){
                    return ans;
                }
            }
            ans += cur;
        }
        return ans;
    }
};