class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(int val : nums){
            hashmap[val]++;
        }
        auto it = std::max_element(hashmap.begin(), hashmap.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second; 
            }
        );
        return it->first;
    }
};