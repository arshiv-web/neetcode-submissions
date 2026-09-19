class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans{0};
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                string temp1 = words[j];
                string temp2 = words[i];
                reverse(temp1.begin(), temp1.end());
                reverse(temp2.begin(), temp2.end());
                ans = ans + (words[j].starts_with(words[i]) && temp1.starts_with(temp2)); 
            }
        }
        return ans;
    }
};