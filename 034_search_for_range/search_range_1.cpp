// Using algorithm function
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> res(2, -1);
        auto bounds = equal_range(nums.begin(), nums.end(), target);
        if(bounds.first == bounds.second)
            return res;
        else{
            res[0] = bounds.first - nums.begin();
            res[1] = bounds.second - nums.begin() - 1;
            return res;
        }
    }
};
