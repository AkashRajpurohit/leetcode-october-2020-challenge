class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> onesPos;
        int n = seats.size();
        int maxDistance = 0;
        
        for(int i = 0; i < n; ++i) {
            if(seats[i] == 1) onesPos.push_back(i);
        }
        
        int m = onesPos.size();
        
        if(onesPos[0] != 0)
            maxDistance = max(maxDistance, onesPos[0]);
        
        for(int i = 0; i < m - 1; ++i)
            maxDistance = max(maxDistance, (onesPos[i + 1] - onesPos[i]) / 2);
        
        if(onesPos[m - 1] != n - 1)
            maxDistance = max(maxDistance, n - 1 - onesPos[m - 1]);
        
        return maxDistance;
    }
};