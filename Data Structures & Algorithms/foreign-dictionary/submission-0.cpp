class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> graph;
        map<char, int> mp; 
        map<int, char> rev; 
        int vo = 0;

        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                if(mp.find(words[i][j]) == mp.end()) {
                    mp[words[i][j]] = vo;
                    rev[vo] = words[i][j]; 
                    vo++;
                    vector<int> temp;
                    graph.push_back(temp);
                } 
            }
        }

        int i = 0;
        int j = 1;

        while (i < words.size() && j < words.size()) {
            string a = words[i];
            string b = words[j];

            int k = 0;
            while (k < a.size() && k < b.size()) {
                if (a[k] == b[k]) {
                    k++;
                } else {
                    graph[mp[a[k]]].push_back(mp[b[k]]);
                    break;
                }
            }

            if (k == b.size() && a.size() > b.size()) {
                return "";
            }

            i++;
            j++;
        }



        vector<int> idg(graph.size(), 0);
        queue<int> q;

        for(int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                idg[graph[i][j]]++;
            }
        }

        for(int i = 0; i < graph.size(); i++) {
            if(idg[i] == 0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()) {
            int node = q.front();
            ans = ans + rev[node];
            for(int i = 0; i < graph[node].size(); i++) {
                idg[graph[node][i]]--;
                if(idg[graph[node][i]] == 0) {
                    q.push(graph[node][i]);
                }
            }
            q.pop();
        }
        if(ans.size() == graph.size()) return ans;
        return "";
    }
};
