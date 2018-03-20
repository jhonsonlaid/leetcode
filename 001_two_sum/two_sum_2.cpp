/*** Two Sum using ONE-PASS Hashtable ***/
/*** jhonsonlaid@gmail.com ***/

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> n2iMap;
        vector<int> res_vec(2, 0);
        for(int i=0; i<nums.size(); ++i)
        {
            int complement = target - nums[i];
            if(n2iMap.find(complement)!=n2iMap.end())
            {
                res_vec[0] = n2iMap.at(complement);
                res_vec[1] = i;
                return res_vec;
            }
            else
            {
                n2iMap.insert(make_pair(nums[i], i));
            }
        }
        //if not found, return(0, 0)
        return res_vec;
    }
};
