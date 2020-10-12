class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        vector<bool> seen(26, false);
        int n = s.size();
        stack<int> sStack;
        
        for(int i = 0; i < n; ++i)
            lastIndex[s[i] - 'a'] = i;
        
        for(int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            
            if(seen[ch]) continue;
            
            while(!sStack.empty() && sStack.top() > ch && i < lastIndex[sStack.top()]) {
                seen[sStack.top()] = false;
                sStack.pop();
            }
            
            sStack.push(ch);
            seen[ch] = true;
        }
        
        string result = "";
        
        while(!sStack.empty()) {
            result.push_back((char) sStack.top() + 'a');
            sStack.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};