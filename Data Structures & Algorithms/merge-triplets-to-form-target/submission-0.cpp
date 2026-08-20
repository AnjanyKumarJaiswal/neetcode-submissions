class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> temp(3);
        for(auto &triplet : triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                temp[0] = max(temp[0],triplet[0]);
                temp[1] = max(temp[1],triplet[1]);
                temp[2] = max(temp[2],triplet[2]);
            }
            if(temp == target){
                return true;
            }
        }
        return false;
    }
};
