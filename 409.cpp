// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        int letter[52] = {0};
        int tmp, ans=0;
        for(int i=0;i<s.length();i++){
            tmp = s[i] - 'A';
            if(tmp <= 25){
                letter[tmp]++;
            }else{
                tmp = s[i] - 'a' + 26;
                letter[tmp]++;
            }
            if(letter[tmp] == 2){
                letter[tmp] = 0;
                ans += 2;
            }
        }
        for(int i=0;i<52;i++){
            if(letter[i] == 1){
                ans += 1;
                break;
            }
        }
        return ans;
    }
};