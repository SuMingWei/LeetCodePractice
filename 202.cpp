// 202. Happy Number
// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        string tmp;
        set<int> shown;
        shown.insert(n);
        int cal = n;
        while(cal != 1){
            tmp = to_string(cal);
            cal = 0;
            for(int i=0;i<tmp.length();i++){
                cal += pow((tmp[i]-'0'),2);
            }
            if(shown.find(cal) != shown.end()) return false;
            else shown.insert(cal);
        }
        
        return true;
    }
};