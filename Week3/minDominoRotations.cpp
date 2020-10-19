class Solution {
private:
    int dominoRotations(vector<int>& A, vector<int>& B) {
        int minSwaps = INT_MAX;
        int n = A.size();
        
        for(int d = 1; d <= 6; ++d) {
            int swaps = 0;
            int i = 0;
            for(; i < n; ++i) {
                if(A[i] == d) continue;
                if(B[i] == d) swaps++;
                else break;
            }
            
            if(i == n) minSwaps = min(minSwaps, swaps);
            swaps = 0;
        }
        
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int AB = dominoRotations(A, B);
        int BA = dominoRotations(B, A);
        
        return AB == -1 ? BA : BA == -1 ? AB : min(AB, BA);
    }
};