class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return;
        for(int i = n-2; i >= 0; i--){
            int min = INT_MAX, min_idx = -1;
            for(int j = i+1; j < n; j++){
                if(nums[j] > nums[i] && nums[j] < min){
                    min = nums[j];
                    min_idx = j;
                }
            }
            if(min_idx != -1){
                int tmp = nums[i];
                nums[i] = nums[min_idx];
                nums[min_idx] = tmp;
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
