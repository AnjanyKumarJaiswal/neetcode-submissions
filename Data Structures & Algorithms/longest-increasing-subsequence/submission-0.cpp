class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(),1);
        int max_len = 0;
        for(int i = nums.size()-1; i>=0;i--){
            for(int j = i+1; j<nums.size();j++){
                if(nums[i]<nums[j]){
                    LIS[i] = max(LIS[i],1+LIS[j]);
                }
            }
            max_len = max(max_len,LIS[i]);
        }
        return max_len;
    }
};