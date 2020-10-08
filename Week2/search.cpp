class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        
        if(n == 0) return -1;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        
        return nums[low] == target ? low : -1;
    }
};