class TimeMap {
private:
    unordered_map<string, vector<int>> mp;
    unordered_map<int, string> message;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        message[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        if(mp[key].size() == 0) return "";
        int timeIdx = upper_bound(mp[key].begin(), mp[key].end(), timestamp) - mp[key].begin();
        if(timeIdx == 0) return "";
        timeIdx--;
        return message[mp[key][timeIdx]];
    }
};
