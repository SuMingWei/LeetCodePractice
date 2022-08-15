// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    struct node{
        string s;
        int num;
    };
    static bool compare(const node& a, const node& b){
        if(a.num == b.num){
            return a.s < b.s;
        }
        return a.num > b.num;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<node> freq;
        vector<string> ans;
        set<string> exist;
        for(int i=0;i<words.size();i++){
            if(exist.find(words[i]) == exist.end()){
                exist.insert(words[i]);
                node tmp = {words[i],1};
                freq.push_back(tmp);
            }else{
                for(int j=0;j<freq.size();j++){
                    if(freq[j].s == words[i]) freq[j].num++;
                }
            }
        }
        sort(freq.begin(),freq.end(),compare);
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].s);
        }
        return ans;
    }
};