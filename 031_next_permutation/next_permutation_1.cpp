class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int i = n-1;
        while(i > 0 && nums[i-1] >= nums[i]) i--;
        if(i > 0){
            int j = i+1;
            while(j < n && nums[j] > nums[i-1]) j++;
            swap(nums[j-1], nums[i-1]);
        }
        sort(nums.begin()+i, nums.end());
    }
};
