class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        int n = nums.size(), lo = 0, hi = n - 1, mid;
        while(lo <= hi ){
			mid = (lo + hi) / 2;
            if(target >= nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if(hi <= n && nums[hi-1] == target) res[1] = nums[hi-1];

        lo = 0; hi = n - 1;
        while(lo <= hi ){
			mid = (lo + hi) / 2;
            if(target <= nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if(hi + 1 >= 0 && nums[hi+1] == target) res[0] = nums[hi+1]

        return res;
    }
};
