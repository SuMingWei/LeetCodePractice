// 733. Flood Fill
// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    struct pos{
        int x;
        int y;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ori = image[sr][sc];
        if(ori == color) return image;
        queue<pos> visit;
        pos start;
        start.x = sr;
        start.y = sc;
        visit.push(start);
        
        while(!visit.empty()){
            int x = visit.front().x;
            int y = visit.front().y;
            image[x][y] = color;
            // up
            if(x-1 >= 0 && image[x-1][y] == ori){
                pos tmp;
                tmp.x = x-1;
                tmp.y = y;
                visit.push(tmp);
            }
            // down
            if(x+1 <= image.size()-1 && image[x+1][y] == ori){
                pos tmp;
                tmp.x = x+1;
                tmp.y = y;
                visit.push(tmp);
            }
            // left
            if(y-1 >= 0 && image[x][y-1] == ori){
                pos tmp;
                tmp.x = x;
                tmp.y = y-1;
                visit.push(tmp);
            }
            // right
            if(y+1 <= image[0].size()-1 && image[x][y+1] == ori){
                pos tmp;
                tmp.x = x;
                tmp.y = y+1;
                visit.push(tmp);
            }
            visit.pop();
        }
        return image;
    }
};