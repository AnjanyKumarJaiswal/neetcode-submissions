class Solution {
public:
    set<pair<int,int>> visited;
    int dfs(int r , int c , int rows , int cols,vector<vector<int>>& grid){
        if(r<0 || r == rows || c<0 || c==cols || grid[r][c] == 0 || visited.find({r,c}) != visited.end()){
            return 0;
        }
        visited.insert({r,c});

        return 1+dfs(r+1,c,rows,cols,grid)
                +dfs(r-1,c,rows,cols,grid)
                +dfs(r,c+1,rows,cols,grid)
                +dfs(r,c-1,rows,cols,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size() , cols = grid[0].size();
        int area = 0;
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                area = max(area,dfs(r,c,rows,cols,grid));
            }
        }
        return area;
    }
};