// 394. Decode String
// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        vector<string> ans;
        string tmp = "";
        string numString = "";
        ans.push_back("");
        for(int i=0;i<s.length();i++){
            if(s[i] == '['){
                ans.push_back("");
                num.push(stoi(numString));
                numString = "";
            }else if(s[i] == ']'){
                tmp = ans.back();
                if(ans.size() != 1) ans.erase(ans.end());   
                else ans[ans.size()-1] == "";
                
                for(int j=0;j<num.top();j++){
                    ans[ans.size()-1] += tmp;
                }
                num.pop();
            }else if(s[i] - 'a' < 0){
                numString += s[i];
            }else{
                ans[ans.size()-1] += s[i];
            }
        }
        return ans[0];
        
    }
};