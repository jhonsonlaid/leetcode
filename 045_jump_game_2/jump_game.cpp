/* Time Limit Exceeded
 */
class Solution{
private:
	void forward(vector<int>& nums, int s, int sum, int ss, int& ms){
		for (int i = 1; i <= nums[s]; i++){
			if ((sum + i) == nums.size() - 1){
				ms = min(ss+1, ms);
				continue;
			}
			if (s + i < nums.size()){
				forward(nums, s + i, sum + i, ss+1, ms);
			}
		}
	}

public:
	int jump(vector<int>& nums){
		if (nums.size() == 1) return 0;
		int ms = INT_MAX;
		forward(nums, 0, 0, 0, ms);
		return ms;
	}

};

