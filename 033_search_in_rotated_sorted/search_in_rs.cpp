class Solution{
public:
    int search(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1, mid;
        while(left >= 0 && right < nums.size() && left <= right){
			mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            // left part is sorted 4567 8 9123
            if(nums[mid] > nums[right])
            {
                if(target > nums[mid])
                    left = mid+1;
                else if(target > nums[right])
                    right = mid-1;
                else if(target <= nums[right])
                    left = mid+1;
            }
            // right part is sorted, 7891 2 3456
            else if(nums[left] > nums[mid]){
                if(target < nums[mid])
                    right = mid-1;
                else if(target <= nums[right])
                    left = mid+1;
                else if(target > nums[right])
                    right = mid-1;
            }
            //left part and right part is sorted
			else{
				if(target > nums[mid]) left = mid+1;
				if(target < nums[mid]) right = mid-1;
			}
        }
        return -1;
    }
};
