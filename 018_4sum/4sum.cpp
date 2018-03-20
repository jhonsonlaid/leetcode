/** O(n^3), same as problem 015_3sum
 *
 */
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int i, j, n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(n < 4) return res;
        for(i = 0; i < n - 3; i++){
            for(j = i+1; j < n - 2; j++){
                int t = target - nums[i] - nums[j];
                int front = j+1, back = n-1;
                while(back > front){
                    int sum = nums[front] + nums[back];
                    if(sum > t) back--;
                    else if(sum < t) front++;
                    else{
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        while(front < n - 1 &&nums[front] == nums[front+1]) front++;
                        while(back > 0 && nums[back] == nums[back-1]) back--;
						front++; back--;
                    }
                }
                while(j < n - 1 && nums[j] == nums[j+1]) j++;
            }
            while(i < n - 1 && nums[i] == nums[i+1]) i++;
        }
		return res;
    }
};
