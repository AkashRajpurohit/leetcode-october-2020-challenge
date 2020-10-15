class Solution {
private:
    int rob(vector<int>& nums, int start, int end) {
        int prevTwo = 0, prevOne = 0, maxVal = 0;
        
        for(int i = start; i < end; ++i) {
            maxVal = max(prevTwo + nums[i], prevOne);
            prevTwo = prevOne;
            prevOne = maxVal;
        }
        
        return prevOne;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int max1 = rob(nums, 0, n - 1);
        int max2 = rob(nums, 1, n);
        
        return max(max1, max2);
    }
};