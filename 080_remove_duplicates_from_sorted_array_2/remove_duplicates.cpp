class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int i = 0, cnt = 1;
        while(i+1 < nums.size()){
            if(nums[i] == nums[i+1]){
                if(cnt > 1){
                    nums.erase(nums.begin()+i+1);
                }
                else{
                    cnt++;
                    i++;
                }
            }
            else{
                i++;
                cnt = 1;
            }
        }
        return nums.size();
    }
};
