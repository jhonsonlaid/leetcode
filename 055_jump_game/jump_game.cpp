class Solution{
public:
    bool canJump(vector<int>& nums){
        if(nums.size() < 2 )  return true;
        for(int i = 0; i < nums.size();){
            int max_idx = i + nums[i];
            int max_dist = i + nums[i];
            for(int j = i; j < i + nums[i]; j++){
                int idx = j + nums[j];
                if(idx >= nums.size() - 1)
                    return true;
                if(idx > max_dist){
                    max_idx = j;
                    max_dist = j + nums[j];
                    break;
                }
            }
            cout << max_idx << endl;
            if(max_idx == i) return false;
            i = max_idx;
        }
        return false;
    }
};
