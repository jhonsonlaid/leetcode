class Solution{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums){
		vector<vector<int>> res;
		forward(res, nums, 0);
		return res;
	}

	void forward(vector<vector<int>>& res, vector<int> nums, int start){
		if (start >= nums.size()){
			res.push_back(nums);
			return;
		}
		vector<int> uniq;
		for (int i = start; i < nums.size(); i++){
			bool go = true;
			for (int j = 0; j < uniq.size(); j++){
				if (uniq[j] == nums[i]) go = false;
			}
			if (!go) continue;
			uniq.push_back(nums[i]);
			swap(nums[start], nums[i]);
			forward(res, nums, start + 1);
			swap(nums[start], nums[i]);
		}
	}
};
