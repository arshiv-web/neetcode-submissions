class DSU{
private:
    vector<int> rank;
    vector<int> par;
public:
    DSU(int n): rank(n, 0), par(n){
        for(int i{0}; auto &x: par){
            x = i++; 
        }
    }
    int parent(int a){
        return par[a] = par[a] == a ? a : parent(par[a]);
    }

    bool unite(int a, int b){
        int x{parent(a)};
        int y{parent(b)};

        if(x == y){
            return false;
        }

        if(rank[x] < rank[y]){
            par[x] = y;
        } else if(rank[x] > rank[y]){
            par[y] = x;
        } else {
            par[x] = y;
            rank[y]++;
        }
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int components{n};
        for(auto &edge: edges){
            if(dsu.unite(edge[0], edge[1])) {
                components--;
            }
        }
        return components;
    }
};
