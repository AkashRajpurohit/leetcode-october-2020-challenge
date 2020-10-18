class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        int n = s.size();
        vector<string> res;
        
        if(n < 10) return {};
        
        for(int i = 0; i + 10 <= n; ++i) {
            string sub = s.substr(i, 10);
            seen[sub]++;
            
            if(seen[sub] == 2) {
                res.push_back(sub);
            }
        }
        
        return res;
    }
};