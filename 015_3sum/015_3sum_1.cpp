class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        //return value not index, so we can sort first
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size()-1;)
        {
            int target = -nums[i];
            // find from index > i , to avoid duplicate items
            int front = i + 1, back = n - 1;
            while(front > back){
                int sum = nums[front] + nums[back];
                if(sum > target) back--;
                if(sum < target) front++;
                if( sum == target){
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[front];
                    tmp[2] = nums[back];
                    res.push_back(tmp);
                    for(int j = i+1; j < nums.size() && nums[j] == nums[i]; j++);
                    i = j;
                    for(int k = front+1; k < nums.size() && nums[front] == nums[k]; k++);
                    front = k;
                    for(int l = back-1; k > front && nums[l] == nums[back]; l--);
                    back = l;
                }
            }
        }
        return res;
    }
};
