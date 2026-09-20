class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        
        vector<int> freq1(26, 0);
        for(auto &x: s1){
            freq1[x - 'a']++;
        }

        vector<int> freq2(26, 0);
        int i{0};
        int j{static_cast<int>(s1.size()) - 1};

        for(int k{i}; k < j; k++){
            freq2[s2[k] - 'a']++;
        }

        while(j < s2.size()){
            freq2[s2[j] - 'a']++;
            for(int x = i; x <=j; x++){
                cout << s2[x];
            }
            cout << ":: ";
            for(int x = 0; x < 26; x++){
                cout << freq2[x];
            }
            cout << endl;

            if(freq1 == freq2){
                return true;
            }
            freq2[s2[i] - 'a']--;
            i++;
            j++;
        }
        return freq1 == freq2;
    }
};
