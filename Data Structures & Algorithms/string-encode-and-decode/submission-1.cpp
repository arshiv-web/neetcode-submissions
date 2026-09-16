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
            while(s[i]!=':') {
                size = size * 10 + (s[i] - 48);
                i++;
            }
            i++;
            while(size > 0) {
                temp+=s[i++];
                size--;
            }
            ans.push_back(temp);
            temp = "";
        }
        return ans;
    }
};
