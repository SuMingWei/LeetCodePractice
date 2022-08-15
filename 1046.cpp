// 1046. Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(!stones.empty()){
            if(stones.size() == 1) return stones[0];
            sort(stones.begin(),stones.end(),greater<int>());
            if(stones[0] == stones[1]){
                stones.erase(stones.begin(),stones.begin()+2);
            }else{
                stones[1] = stones[0] - stones[1];
                stones.erase(stones.begin());
            }

        }
        return 0;
    }
};