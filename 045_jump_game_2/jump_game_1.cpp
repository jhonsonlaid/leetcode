/* O(N) time
 */
class Solution{
public:
	int jump(vector<int>& nums){
		int count = 0;
		if (nums.size() == 1) return 0;
		for (int i = 0; i < nums.size();){
			int max_step = 0, max_i = 0;
			for (int j = 1; j <= nums[i]; j++){
				if (i + j >= nums.size()-1) return count + 1;
				if (nums[i+j] + j > max_step){
					max_step = nums[i+j] + j;
					max_i = j;
				}
			}
			count++;
			i += max_i;
		}
		return count;
	}
};
