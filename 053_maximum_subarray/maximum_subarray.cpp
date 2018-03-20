class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int sum = 0, max_sum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(sum < 0){
                sum = [i];
            }
            else{
                sum += nums[i];
            }
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
