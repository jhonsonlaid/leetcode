class Solution{
public:
    int firstMissingPositive(vector<int>& nums){
        sort(nums.begin(), nums.end());

        if(nums.empty()) return 1;

        if(nums[0] > 1) return 1;
        
        if(nums.size() == 1) return nums[0] > 0 ? 2 : 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i-1] >= 0){
               if(nums[i] > nums[i-1] + 1)
                   return nums[i-1] + 1;
            }

            if(nums[i] > 0 && nums[i-1] < 0){
                if(nums[i] > 1) return 1;
			}
        }
		return nums[nums.size()-1]+1;
    }
};
