class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        if(n == 0) return 0;
        
        sort(tokens.begin(), tokens.end());
        
        int i = 0, j = n - 1, score = 0, maxScore = 0;
        
        while(i <= j) {
            if(tokens[i] <= P) {
                P -= tokens[i++];
                score++;
                maxScore = max(maxScore, score);
            } else if(score > 0) {
                P += tokens[j--];
                score--;
            } else {
                return maxScore;
            }
        }
        
        return maxScore;
    }
};