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
        // pair<int, char> storedCand = {-1, 'x'};

        // cc, b

        while(!st.empty()) {
            auto [f, cand] = *st.begin();
            st.erase(st.begin());

            if(temp.size() >= 2){
                if(temp[temp.size() - 1] == cand && temp[temp.size() - 2] == cand) {
                    
                    if(st.empty()) break;
                    
                    auto [f2, cand2] = *st.begin();
                    st.erase(st.begin());

                    temp = temp + cand2;
                    if(f2 - 1 > 0){
                        st.insert({f2 - 1, cand2});
                    }

                    st.insert({f, cand});
                    continue;
                }
            }

            temp = temp + cand;
            if(f - 1 > 0){
                st.insert({f - 1, cand});
            }
        }
        return temp;
    }
};