class Solution {
public:
    set<int> visitedNodes;
    set<int> cycle;
    vector<int> visitOrder;
    unordered_map<int, vector<int>> premap;
    bool dfs(int crs) {
        if(cycle.find(crs) != cycle.end()) return false;
        if (visitedNodes.find(crs) != visitedNodes.end()) return true;
        cycle.insert(crs);
        for (auto &preq : premap[crs]) {
            if (!dfs(preq)) return false;
        }
        cycle.erase(crs);
        visitedNodes.insert(crs);
        visitOrder.push_back(crs);
        premap[crs] = {}; 
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto &pq : prerequisites) {
            premap[pq[0]].push_back(pq[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return {};
        }
        return visitOrder;
    }
};