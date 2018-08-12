class Solution{
public:
    void helper(vector<vector<int>>& res, vector<int>& nums, int k){
        vector<int> row(nums.begin(), nums.begin()+k);
        res.push_back(row);
        for(int i = k; i < nums.size(); i++){
            if(k > 0 && nums[i] < nums[k-1]) continue;
            swap(nums[k], nums[i]);
            helper(res, nums, k+1);
            swap(nums[k], nums[i]);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
};
