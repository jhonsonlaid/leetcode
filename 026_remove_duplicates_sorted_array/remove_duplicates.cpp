class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int u = 0;
        for(int i = 1; i < nums.size(); i++){
            while(nums[u] == nums[i]) i++;
            if(i < nums.size())
            {
                nums[++u] = nums[i];
            }
        }
        return u+1;
    }
};
