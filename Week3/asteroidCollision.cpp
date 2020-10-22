class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        for(int x: asteroids) {
            if(x > 0) {
                s.push(x);
            } else {
                while(!s.empty() && s.top() > 0 && s.top() < abs(x))
                    s.pop();
                
                if(s.empty() || s.top() < 0)
                    s.push(x);
                else if(s.top() == abs(x))
                    s.pop();
            }
        }
        
        vector<int> ans;
        
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};