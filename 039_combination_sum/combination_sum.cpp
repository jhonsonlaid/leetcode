class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        vector<int> buf;
		sort(candidates.begin(), candidates.end());
        forward(candidates, res, buf, candidates[0], target, 0);
        return res;
    }

    void forward(vector<int>& cand, vector<vector<int>>& res, vector<int> buf, int in, int target, int sum){
        for(int i = 0;  i < cand.size() && cand[i] <= target; i++){
			if(cand[i] >= in && sum < target){
				//cout << in << cand[i] << sum << endl;
				//申请新的buf 和 sum，将新值传递到下一次递归
				//而且能够保：证在本次递归中sum的值统一。
				vector<int> nbuf(buf);
				nbuf.push_back(cand[i]);
				int nsum = sum + cand[i];

				if(nsum == target)
            	    res.push_back(nbuf);

                forward(cand, res, nbuf, cand[i], target, nsum);
            }
		}
    }
};
