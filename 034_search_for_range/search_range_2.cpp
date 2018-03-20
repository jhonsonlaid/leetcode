// recursive version
// actually like making while(..) as a recursion
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> res(2, -1);
        if(nums.empty()) return res;
		res[0] = nums.size();
        search(nums, target, 0, nums.size()-1, res);
        // didnot find
        if(res[0] == nums.size()) res[0] = -1;
        return res;
    }
    void search(vector<int>& nums, int target,int lo, int hi, vector<int>& res){

		if(lo > hi) return;

        int mid = (lo + hi) / 2;
        if(target > nums[mid])
			search(nums, target, mid + 1, hi, res);
        else if(target < nums[mid])
			search(nums, target, lo, mid - 1, res);
        else{
			// nums[mid] == target, then save it as res
			if(mid < res[0]){
				res[0] = mid;
				search(nums, target, lo, mid - 1, res);
			}
			if(mid > res[1]){
				res[1] = mid;
				search(nums, target, mid + 1, hi, res);
			}
        }
    }
};
