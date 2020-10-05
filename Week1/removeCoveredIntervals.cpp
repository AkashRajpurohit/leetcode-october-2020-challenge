class Solution {
public:
    static bool compare(vector<int> i1, vector<int> i2) {
        return i1[0] < i2[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int n = intervals.size();
        
        if(n <= 1) return n;
        
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> curr = {-1, -1};
        
        for(vector<int> in: intervals) {
            if(in[0] > curr[0] && in[1] > curr[1]) {
                count++;
                curr[0] = in[0];
            }
            
            curr[1] = max(curr[1], in[1]);
        }
        
        return count;
    }
};