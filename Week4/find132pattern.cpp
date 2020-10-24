/*
    O(n^2) Time and O(1) Space
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2) return false;
        
        int leftMin = INT_MAX;
        
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(nums[j] > leftMin && nums[i] > nums[j]) 
                    return true;
            }
            leftMin = min(leftMin, nums[i]);
        }
        
        return false;
    }
};

/*
    O(N) Time and O(N) Space
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int mins[n];
        
        mins[0] = nums[0];
        for(int i = 1; i < n; ++i)
            mins[i] = min(mins[i - 1], nums[i]);
        
        stack<int> s;
        
        for(int j = n - 1; j >= 0; --j) {
            if(nums[j] > mins[j]) {
                while(!s.empty() && s.top() <= mins[j])
                    s.pop();
                
                if(!s.empty() && s.top() < nums[j])
                    return true;
                
                s.push(nums[j]);
            }
        }
        
        return false;
    }
};