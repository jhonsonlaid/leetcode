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
		for (int i = start; i < nums.size(); i++){
			swap(nums[start], nums[i]);
			forward(res, nums, start + 1);
			swap(nums[start], nums[i]);
		}
	}
};
