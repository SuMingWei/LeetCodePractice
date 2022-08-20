// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();

        map<char,int> mp;
        int maxTask = 0;
        char mainTask = tasks[0];
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i]) != mp.end()){
                mp[tasks[i]]++;  
                if(mp[tasks[i]] > maxTask){
                    maxTask = mp[tasks[i]];
                    mainTask = tasks[i];
                }
            }else mp[tasks[i]] = 1;
        }

        int time = maxTask + n*(maxTask-1);
        for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second == maxTask && it->first != mainTask){
                time++;
            }
        }
        
        return max(time, (int)tasks.size());
    }
};