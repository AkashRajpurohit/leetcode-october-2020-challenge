class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        
        int i = 0, j = n - 1;
        
        while(i >= 0 && j >= 0 && i < m && j < n) {
            if(matrix[i][j] == target) return true;
            
            if(matrix[i][j] < target) i++;
            else j--;
        }
        
        return false;
    }
};