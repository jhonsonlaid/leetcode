class Solution{
public:
    int removeElement(vector<int>& nums, int val){
        int len = 0, n = nums.size();
        for(int i = 0; i < n-len;){
            if(nums[i] == val){
                int tmp = nums[i];
                nums[i] = nums[n-1-len];
                nums[n-1-len]  = tmp;
                len++;
            }
            else{
                i++;
            }
        }
        return n-len;
    }
};
