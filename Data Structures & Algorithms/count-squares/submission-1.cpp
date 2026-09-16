class CountSquares {
private:
    map<vector<int>, int> mp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(auto &p: mp) {
            if(p.first[0] != x && p.first[1] == y) {
                vector<int> a(2);
                vector<int> b(2);
                if(p.first[0] < x) {
                    a[0] = p.first[0];
                    b[0] = x;
                } else {
                    a[0] = x;
                    b[0] = p.first[0];
                }
                a[1] = b[1] = y;

                int d = b[0] - a[0];
                
                vector<int> c1 = {a[0], a[1] + d};
                vector<int> d1 = {b[0], b[1] + d};

                vector<int> c2 = {a[0], a[1] - d};
                vector<int> d2 = {b[0], b[1] - d};

                ans += (p.second*mp[c1]*mp[d1]) + (p.second*mp[c2]*mp[d2]);
            }

        }
        return ans;

    }
};
