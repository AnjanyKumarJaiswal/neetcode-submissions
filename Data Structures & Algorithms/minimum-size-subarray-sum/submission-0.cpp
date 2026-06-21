class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, l = 0;
        int subarr = INT_MAX;
        for(int r = 0; r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                subarr = min(subarr,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return subarr == INT_MAX ? 0 : subarr;
    }
};