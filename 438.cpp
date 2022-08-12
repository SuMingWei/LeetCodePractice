// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phrase(26,0), cur(26,0); // can't use arr to compare
        int cnt;
        vector<int> ans;
        if(s.length() < p.length()) return ans;
        
        for(int i=0;i<p.length();i++){
            cur[s[i]-'a']++;
            phrase[p[i]-'a']++;
        }
        if(cur == phrase) ans.push_back(0);

        for(int i=0;i<(s.length()-p.length());i++){
            // cout << s[i] << " " << s[i+p.length()] << "\n";
            cur[s[i]-'a']--;
            cur[s[i+p.length()]-'a']++;
            if(cur == phrase) ans.push_back(i+1);
        }
        return ans;
    }
};