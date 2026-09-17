class DSU{
private:
    vector<int> parent;
    vector<int> height;
public:
    DSU(int n): parent(n), height(n, 0) {
        for(int i = 0; i < n; i++ ){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x]!=x) return parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y)
            return false;
        
        if(height[x] < height[y]){
            parent[x] = y;
        } else if(height[y] < height[x]){
            parent[y] = x;
        } else {
            parent[y] = x;
            height[x]++;
        }
        return true;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       DSU dsu(edges.size());
       for(int i = 0; i < edges.size(); i++){
            if(dsu.unite(edges[i][0]-1, edges[i][1] - 1)){
                continue;
            }
            return edges[i];  
       }
    }
};
