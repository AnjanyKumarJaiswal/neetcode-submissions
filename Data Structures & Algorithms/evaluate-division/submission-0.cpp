class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            auto &eq = equations[i];
            string a = eq[0]; 
            string b = eq[1];
            adj[a].push_back({b,values[i]});
            adj[b].push_back({a,1/values[i]});
        }

        auto bfs = [&adj](string src , string target){
            if((adj.find(src) == adj.end()) || (adj.find(target)== adj.end())){
                return -1.0;
            };

            deque<pair<string,double>> q;
            unordered_set<string> visit;

            q.push_back({src,1.0});
            visit.insert(src);

            while(!q.empty()){
                auto val = q.front();
                q.pop_front();
                string n = val.first;
                double w = val.second;
                if(n == target) {
                    return w;
                }
                for(auto &curr : adj[n]){
                    string nei = curr.first;
                    double weight = curr.second;
                    if(visit.find(nei)==visit.end()){
                        q.push_back({nei,w*weight});
                        visit.insert(nei);
                    }
                }
            }
            return -1.0;
        };
        vector<double> res;
        for(int i=0; i<queries.size(); i++){
            auto &q = queries[i];
            string x = q[0];
            string y = q[1];
            res.push_back(bfs(x,y));
        }
        return res;
    }
};