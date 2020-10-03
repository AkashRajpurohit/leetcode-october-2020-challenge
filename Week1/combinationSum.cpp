class Solution {
private:
    void findCombinations(vector<int>& candidates, int index, int target, vector<int> current, vector<vector<int>>& result) {
        if(target < 0) return;
        if(target == 0) {
            result.push_back(current);
            return;
        }
        
        for(int i = index; i < candidates.size(); ++i) {
            if(candidates[i] <= target) {
                current.push_back(candidates[i]);
                findCombinations(candidates, i, target - candidates[i], current, result);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        
        sort(candidates.begin(), candidates.end());
        
        findCombinations(candidates, 0, target, vector<int>(), result);
        
        return result;
    }
};