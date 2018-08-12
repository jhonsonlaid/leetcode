class Solution{
public:
    void helper(vector<vector<int>>&res, vector<int>& v, int k, int lvl){
        if(lvl == k){
            vector<int> row(v.begin(), v.begin()+k);
            res.push_back(row);
            return;
        }
        for(int i = lvl; i < v.size(); i++){
            if(lvl > 0 && v[i] < v[lvl-1]) continue;
            swap(v[lvl], v[i]);
            helper(res, v, k, lvl+1);
            swap(v[lvl], v[i]);
        }
    }
    vector<vector<int>> combine(int n, int k){
        vector<int> v(n);
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
            v[i] = i + 1;
        helper(res, v, k, 0);
        return res;
    }
};
