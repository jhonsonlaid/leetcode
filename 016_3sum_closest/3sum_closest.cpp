class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int res, dis = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            int front = i+1, back = nums.size() - 1;
            int t = nums[i] - target;
            while(back > front){
                int sum = nums[front] + nums[back];
                if(abs(t - sum - nums[i]) < abs(dis))
                    dis = t - sum - nums[i];
                if(sum > t) back--;
                else if(sum < t) front++;
                else return target;
            }
        }
        return dis + target;
    }
};
