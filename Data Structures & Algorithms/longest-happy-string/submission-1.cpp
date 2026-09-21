class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        set<pair<int, char>, greater<>> st;
        if(a > 0)
            st.insert({a, 'a'});
        if(b > 0)
            st.insert({b, 'b'});
        if(c > 0)
            st.insert({c, 'c'});
        string temp{""};
        pair<int, char> storedCand = {-1, 'x'};

        while(!st.empty()) {
            auto [f, cand] = *st.begin();
            st.erase(st.begin());

            if(temp.size() >= 2){
                if(temp[temp.size() - 1] == cand && temp[temp.size() - 2] == cand) {
                    storedCand = {f, cand};
                    continue;
                }
            }

            temp = temp + cand;
            if(f - 1 > 0){
                st.insert({f - 1, cand});
            }

            if(storedCand.first != -1){
                st.insert(storedCand);
                storedCand = {-1, 'x'};
            }
        }
        return temp;
    }
};