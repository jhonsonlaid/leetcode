class Solution{
public:
    bool canJump(vector<int>& nums){
        int dst = 0;
        if(nums.size() <= 1) return true;
        for(int i = 0; i < nums.size(); ){
            dst = max(nums[i], dst);
            if(i + dst >= nums.size() - 1)
                return true;
            if(dst <= 0)
                return false;
            dst--;
        }
        return false;
    }
};
