class Solution {
public:
    unordered_map<int,vector<int>> adjMap;
    set<int> visit;
    bool dfs(int val , int prev){
        if(visit.find(val) != visit.end()) return false;
        visit.insert(val);
        for(auto &i : adjMap[val]){
            if(i==prev) continue;
            if(!dfs(i,val)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==0) return true;
        for(int i = 0; i<n; i++){
            adjMap[i] = {};
        }
        for(auto &edg : edges){
            adjMap[edg[1]].push_back(edg[0]);
            adjMap[edg[0]].push_back(edg[1]);
        }
        return (dfs(0,-1) && n==visit.size());
    }
};
