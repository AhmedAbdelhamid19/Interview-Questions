class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        logs[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) { 
        int l=0, r=logs[key].size()-1, ans=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if(logs[key][mid].first<=timestamp) {
                ans = mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return ans == -1 ? "" : logs[key][ans].second;
    }
private:
    map<string, vector<pair<int, string>>> logs;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
