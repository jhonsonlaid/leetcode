class Solution{
public:
    int search(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1, mid;
        while(left <= right){
			mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            // left part is sorted 4567 8 9123 or 1234 5 6789
            // "=" for right = left + 1, i.e. 3, 1
            if(nums[mid] >= nums[left]){
                if(target < nums[mid] && target >= nums[left])
                    right = mid-1;
                // smaller than nums[left] or greater than nums[mid]
                else
                    left = mid+1;
            }
            // right part is sorted, 7891 2 3456
            else{
                if(target > nums[mid] && target <= nums[right])
                    left = mid+1;
                // greater than nums[right] or smaller than nums[mid]
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};
