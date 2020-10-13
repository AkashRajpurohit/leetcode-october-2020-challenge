class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        
        unordered_set<char> setA, setB;
        bool repeatA = false, repeatB = false;
        vector<int> pos;
        int n = A.size();
        
        for(int i = 0; i < n; ++i) {
            char a = A.at(i);
            char b = B.at(i);
            
            if(setA.find(a) != setA.end()) 
                repeatA = true;
            
            if(setB.find(b) != setB.end()) 
                repeatB = true;
            
            setA.insert(a);
            setB.insert(b);
            
            if(a != b) pos.push_back(i);
        }
        
        if(pos.size() == 2) {
            if(A[pos[0]] == B[pos[1]] && A[pos[1]] == B[pos[0]])
                return true;
        }
        
        if(A == B && repeatA && repeatB)
            return true;
        
        return false;
    }
};