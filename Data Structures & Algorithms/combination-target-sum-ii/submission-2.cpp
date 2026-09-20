class Solution {
public:
    void run(vector<int>& candidates, int target, vector<int> &temp, int idx, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(idx >= candidates.size() || target < 0) return;
        temp.push_back(candidates[idx]);
        run(candidates, target - candidates[idx], temp, idx+1, res);
        temp.pop_back();

        int next{idx+1};
        while(next < candidates.size() && candidates[next] == candidates[idx]){
            next++;
        }
        run(candidates, target, temp, next, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        run(candidates, target, temp, 0, res);
        return res;
    }
};
