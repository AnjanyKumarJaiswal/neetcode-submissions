class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> hashmap;
        priority_queue<int, vector<int>, greater<int>> minH;
        if(hand.size() % groupSize != 0) return false;
        for(int val : hand){
            hashmap[val]++;
        }
        for(auto &[key,val]: hashmap){
            minH.push(key);
        }
        while(!minH.empty()){
            int first = minH.top();
            for(int i = first; i<first+groupSize; i++){
                if(hashmap.find(i)==hashmap.end()) return false;
                hashmap[i]-=1;
                if(hashmap[i]==0){
                    if(i!=minH.top()){
                        return false;
                    }
                    minH.pop();
                }
            }
        }
        return true;
    }
};
