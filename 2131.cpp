// 2131. Longest Palindrome by Concatenating Two Letter Words
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> s;
        string rev;
        int ans=0; 
        int center = 0;
        for(int i=0;i<words.size();i++){
            if(words[i][0] == words[i][1]){
                if(s.count(words[i]) == 1){
                    center--;
                    ans += 4;
                    s[words[i]]--;
                    if(s[words[i]] == 0){
                        s.erase(words[i]);   
                    }
                }else{
                    center++;
                    s[words[i]]++;
                }
            }else{
                rev = "";
                rev.push_back(words[i][1]);
                rev.push_back(words[i][0]);

                if(s.count(rev) == 1){
                    ans += 4;
                    s[rev]--;
                    if(s[rev] == 0) s.erase(rev);   
                }else{
                    s[words[i]]++;
                }
                // cout << rev << " "<<ans << endl;
                
            }
        }
        if(center > 0) ans += 2;
        return ans;
    }
};