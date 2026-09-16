class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";
        for(auto x: strs){
            temp+=to_string(x.size()) + ":" + x;
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        int size = 0;
        for(int i = 0; i<s.size();){
            int colon = s.find(':', i);
            int size = stoi(s.substr(i, colon - i));
            ans.push_back(s.substr(colon + 1, size));
            i = colon + 1 + size;
        }
        return ans;
    }
};
