class Solution{
public:
    void sortColors(vector<int>& nums){
        int p0, p2;
        p0 = 0, p2 = nums.size()-1;
        for(int i = 0; i <= p2; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[p0++]);
            }
            else if(nums[i] == 2){
                while(p2 >= 0 && nums[p2] == 2)
                    p2--;
                if(p2 < i ) break;
                swap(nums[i], nums[p2--]);
                if(nums[i] == 0)
                    swap(nums[i], nums[p0++]);
            }
        }
    }
};
