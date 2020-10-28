class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        
        if(n == 0) return result;
        
        int start = nums[0], end = nums[0];
        string val;
        
        for(int i = 1; i < n; ++i) {
            if(end + 1 == nums[i]) {
                end = nums[i];
                continue;
            }
            
            if(start == end) {
                val = to_string(start);
                result.push_back(val);
            } else {
                val = to_string(start) + "->" + to_string(end);
                result.push_back(val);
            }
            
            start = nums[i];
            end = nums[i];
        }
        
        if(start == end) {
            val = to_string(start);
            result.push_back(val);
        } else {
            val = to_string(start) + "->" + to_string(end);
            result.push_back(val);
        }
        
        return result;
    }
};