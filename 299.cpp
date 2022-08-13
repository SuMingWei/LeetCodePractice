// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int freq[1005] = {0};
        queue<int> bulls;
        int a=0, b=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]){
                bulls.push(i);
                a++;
            }else{
                freq[secret[i]]++;
            }
        }
        for(int i=0;i<secret.length();i++){
            if(bulls.front() == i){
                bulls.pop();
            }else{
                if(freq[guess[i]] > 0){
                    freq[guess[i]]--;
                    b++;
                }
            }
        }
        string ans = to_string(a) + 'A' + to_string(b) + 'B';
        return ans;
    }
};