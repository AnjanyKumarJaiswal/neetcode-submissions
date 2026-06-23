class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        set<pair<int,int>> visit;

        auto invalid = [&](int r, int c){
            return r < 0 || c < 0 || r >= n || c >= n;
        };

        function<void(int,int)> dfs = [&](int r, int c){
            if(invalid(r,c) || grid[r][c] == 0 || visit.count({r,c}))
                return;

            visit.insert({r,c});

            for(auto &[dr,dc] : directions)
                dfs(r + dr, c + dc);
        };

        auto bfs = [&]() -> int {
            int res = 0;
            deque<pair<int,int>> q(visit.begin(), visit.end());
            while(!q.empty()) {
                int sz = q.size();
                for(int i = 0; i < sz; i++) {
                    auto [r,c] = q.front();
                    q.pop_front();

                    for(auto &[dr,dc] : directions) {
                        int nr = r + dr;
                        int nc = c + dc;

                        if(invalid(nr,nc) || visit.count({nr,nc}))
                            continue;

                        if(grid[nr][nc] == 1)
                            return res;

                        visit.insert({nr,nc});
                        q.push_back({nr,nc});
                    }
                }
                res++;
            }
            return -1;
        };
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 1) {
                    dfs(r,c);
                    return bfs();
                }
            }
        }

        return -1;
    }
};