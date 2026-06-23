class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int firstVal = nums[0]*nums[1];
        int lastVal = nums[nums.size()-1]*nums[nums.size()-2];
        return lastVal-firstVal;
    }
};