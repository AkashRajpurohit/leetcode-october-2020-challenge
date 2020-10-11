class Solution {
public:
    static bool compare(vector<int> P1, vector<int> P2) {
        return P1[1] == P2[1] ? P1[0] < P2[0] : P1[1] < P2[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n <= 1) return n;
        
        sort(points.begin(), points.end(), compare);
        
        int arrow = 1;
        int end = points[0][1];
        
        for(int i = 1; i < n; ++i) {
            if(points[i][0] > end) {
                arrow++;
                end = points[i][1];
            }
        }
        
        return arrow;
    }
};