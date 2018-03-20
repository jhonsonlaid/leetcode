class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        int ns = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < ns; i++) res[i][0] = nums[i];
        forward(res, nums);
    }

    void forward(vector<vector<int>>& res, vector<int> nums){
        vector<vector<int>> buffer;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < res.size(); j++){
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                buffer.push_back(tmp);
            }
            vector<int> new_nums(nums.begin()+1, nums.end());
            res = buffer
            forward(res, new_nums, 1);
        }
    }
};
