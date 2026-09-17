class Solution {
public:
    string getKey(string x){
        string key = "";
        vector<int> freq(26, 0);
        for(int i = 0; i < x.size(); i++){
            freq[x[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            key+=to_string(freq[i]);
            key+=":";
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp; 
        for(auto &x: strs){
            string k = getKey(x);
            mp[k].push_back(x);
        }
        for(auto &x: mp){
            res.push_back(x.second);
        }
        return res;
    }
};
