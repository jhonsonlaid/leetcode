class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> buf;
        forward(candidates, res, buf, target, -1, 0, 0);
		return res;
    }

    void forward(vector<int>& cand, vector<vector<int>>& res, vector<int> buf, int target, int pos, int sum, int start){
        for(int i = 0; i < cand.size() && cand[i] <= target; i++){

            if(i > pos){
				if(cand[start] != cand[i]) start = i; 
				int count = 0;
				for(int k = 0; k < buf.size(); k++)
					if(buf[k] == cand[i]) count++;
				if(i > 0 && cand[i] == cand[i-1] && count <= i-start-1) 
					continue;

                vector<int> nbuf(buf);
                nbuf.push_back(cand[i]);
                int nsum = sum + cand[i];
                if(nsum > target) return;
                if(nsum == target){
                    res.push_back(nbuf);
                    return;
                }

                forward(cand, res, nbuf, target, i, nsum, start);
            }
        }
    }
};
