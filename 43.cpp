// 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        string ans = "", cur = "";
        int carry, tmp;
        int i, j ,k;
        if(num1 == "0" || num2 == "0") return "0";
        for(i=len2-1;i>=0;i--){
            // calculate cur val;
            cur = "";
            carry = 0;
            if(num2[i] == '0') continue;
            for(j=len1-1;j>=0;j--){
                tmp = (num1[j] - '0')*(num2[i]- '0');
                tmp += carry;
                if(tmp > 9){
                    cur = to_string(tmp%10) + cur;
                    carry = tmp/10;
                }else{
                    cur = to_string(tmp) + cur;
                    carry = 0;
                }
            }
            if(carry > 0) cur = to_string(carry) + cur;
            // add to ans;
            if(i != len2-1){
                for(k=0;k<(len2-1-i);k++) cur += "0";
                tmp = cur.length()-ans.length();
                for(int k=0;k<tmp;k++){
                    ans = "0" + ans;
                } 
                carry = 0;
                for(k=cur.length()-1;k>=0;k--){
                    tmp = (cur[k]-'0')+(ans[k]-'0');
                    tmp += carry;
                    if(tmp > 9){
                        ans[k] = to_string(tmp%10)[0];
                        carry = tmp/10;
                    }else{
                        ans[k] = to_string(tmp)[0];
                        carry = 0;
                    }
                }    
                if(carry > 0) ans = to_string(carry) + ans;
            }else{
                ans = cur;
            }
        }
        return ans;
    }
};