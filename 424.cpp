// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int l=0, ans=0, maxFreq=0, curFreq=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]-'A']++;
            curFreq = freq[s[r]-'A'];
            maxFreq = max(maxFreq, curFreq);
            // moving window
            if(r-l+1 - maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
        
    }
};