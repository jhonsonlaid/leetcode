/*** Two Sum using Hashtable ***/
/*** jhonsonlaid@gmail.com ***/

/***NOT WORK for [3,3] 6, as key is unique, so map will only be (3,0)***/
/*** CORRECT SOLUTION see two_sum_2.cpp ***/

#include <map>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> n2iMap;
        for(int i=0; i<nums.size(); ++i)
        {
			n2iMap.insert(pair<int, int>(nums.at(i), i));
        }
        
        for(int j=0; j<n2iMap.size(); ++j)
        {
            int complement = target - nums[j];
            if( n2iMap.find(complement)!=n2iMap.end() && n2iMap.at(complement)!=j)
            {
                int res_array[] = {j, n2iMap.at(complement)};
                vector<int> res_vec(res_array, res_array+2);
                return res_vec;
            }
        }

        vector<int> res_vec(2,0);
        return res_vec;
    }
};
