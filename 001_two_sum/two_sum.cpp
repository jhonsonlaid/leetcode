/*** Tow Sum Brute Force ***/

//#include<vector>
//using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	for(int out=0; out<nums.size()-1; out++)
		for(int in=out+1; in<nums.size(); in++)
		{
			if(out != in)
			{
				if(nums.at(out) + nums.at(in) == target)
				{
                    int res_array[] = {out, in};
                    vector<int> res_vec(res_array, res_array+2);
					return res_vec;
				}
			}
		}
    vector<int> res_vec(2,0);
    return res_vec;
}
