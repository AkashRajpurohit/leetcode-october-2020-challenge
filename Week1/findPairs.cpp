class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int count = 0;
        
        if(n <= 1) return count;
        
        for(int num: nums)
            m[num]++;
        
        for(auto &x: m) {
            if((k == 0 && x.second > 1) || (k > 0 && m.find(x.first - k) != m.end())) count++;
        }
        
        return count;
    }
};