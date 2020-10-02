class RecentCounter {
public:
    vector<int> requests;
    RecentCounter() {
        this->requests = {};
    }
    
    int ping(int t) {
        this->requests.push_back(t);
        int hi = this->requests.size() - 1;
        int lo = 0;
        int mid;
        int lowerLimit = t - 3000;
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if(this->requests[mid] < lowerLimit) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return this->requests.size() - lo;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */