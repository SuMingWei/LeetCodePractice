// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        set<char> used;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i]) == mp.end()){
                if(used.find(t[i]) == used.end()){
                    mp[s[i]] = t[i];
                    used.insert(t[i]);
                }else{
                    return false;
                }
            }else{
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};