class Solution {
public:
    set<pair<int, int>> visit;
    deque<pair<int, int>> dq;

    void addRoom(int r, int c, int ROWS, int COLS, vector<vector<int>>& grid) {
        if (r < 0 || r == ROWS || c < 0 || c == COLS || 
            visit.find({r, c}) != visit.end() || grid[r][c] == -1) {
            return;
        }
        
        visit.insert({r, c});
        dq.push_back({r, c});
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    dq.push_back({i, j});
                    visit.insert({i, j});
                }
            }
        }

        int dist = 0;
        while (!dq.empty()) {
            int level_size = dq.size();
            
            for (int i = 0; i < level_size; i++) {
                pair<int, int> curr = dq.front();
                dq.pop_front();
                
                int r = curr.first;
                int c = curr.second;
                grid[r][c] = dist;

                addRoom(r + 1, c, rows, cols, grid);
                addRoom(r - 1, c, rows, cols, grid);
                addRoom(r, c + 1, rows, cols, grid);
                addRoom(r, c - 1, rows, cols, grid);
            }
            dist += 1;
        }
    }
};