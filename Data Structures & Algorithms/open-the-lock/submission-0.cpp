class Solution {
public:
    vector<string> childtree(string lock){
        vector<string> res;
        string digit;
        for(int i = 0; i<4; i++){
            string temp = lock;
            temp[i] = (lock[i] - '0' + 1) % 10 + '0';
            res.push_back(temp);
            temp[i] = (lock[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(temp);
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        int turns = 0;
        deque<pair<string,int>> dq;
        set<string> visit(deadends.begin(),deadends.end());
        if (visit.count("0000")) return -1;
        dq.push_back({"0000",0});
        while(!dq.empty()){
            pair<string,int> curr = dq.front();
            dq.pop_front();
            string lock = curr.first;
            turns = curr.second;
            if(lock == target) return turns;
            for(auto child : childtree(lock)){
                if(visit.find(child) == visit.end()){
                    visit.insert(child);
                    dq.push_back({child,turns+1});
                }
            }
        }
        return -1;
    }
};