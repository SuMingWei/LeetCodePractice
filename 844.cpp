// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for(int i=0;i<s.length();i++){
            if(s[i] == '#'){
                if(!a.empty()) a.pop();
            } 
            else a.push(s[i]);
        }
        for(int i=0;i<t.length();i++){
            if(t[i] == '#'){
                if(!b.empty()) b.pop();
            } 
            else b.push(t[i]);
        }
        if(a == b) return true;
        return false;
    }
};