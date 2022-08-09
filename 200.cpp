// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    struct pos{
        int x;
        int y;
    };
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        queue<pos> visit;
        pos tmp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    grid[i][j] == '2';
                    island++;
                    tmp.x = i;
                    tmp.y = j;
                    visit.push(tmp);  
                    while(!visit.empty()){
                        int x = visit.front().x;
                        int y = visit.front().y;
                        visit.pop();
                        if(x-1 >= 0 && grid[x-1][y] == '1'){
                            tmp.x = x-1;
                            tmp.y = y;
                            visit.push(tmp);
                            grid[x-1][y] = '2';
                        }
                        if(x+1 <= grid.size()-1 && grid[x+1][y] == '1'){
                            tmp.x = x+1;
                            tmp.y = y;
                            visit.push(tmp);
                            grid[x+1][y] = '2';
                        }
                        if(y-1 >= 0 && grid[x][y-1] == '1'){
                            tmp.x = x;
                            tmp.y = y-1;
                            visit.push(tmp);
                            grid[x][y-1] = '2';
                        }
                        if(y+1 <= grid[0].size()-1 && grid[x][y+1] == '1'){
                            tmp.x = x;
                            tmp.y = y+1;
                            visit.push(tmp);
                            grid[x][y+1] = '2';
                        }
                    }
                }
            }
        }
        return island;
    }
};