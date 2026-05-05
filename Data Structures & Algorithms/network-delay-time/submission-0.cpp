class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for(int i = 0; i<times.size();i++){
            edges[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        minHeap.push({0,k});
        unordered_set<int> visited;
        int res = 0;
        while(!minHeap.empty()){
            auto top_val = minHeap.top();
            minHeap.pop();
            if(visited.find(top_val.second)!=visited.end()){
                continue;
            }
            visited.insert(top_val.second);
            res = max(res,top_val.first);
            for(auto &p : edges[top_val.second]){
                int n2 = p.first;
                int w2 = p.second;
                if(visited.find(n2) == visited.end()){
                    minHeap.push({top_val.first+w2,n2});
                }
            }
        }
        return visited.size() == n ? res : -1;
    }
};