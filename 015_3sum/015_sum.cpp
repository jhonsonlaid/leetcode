/*** Using two map Count[value] = count, Value[value] = index
 * Time Complexity O(n^2), ---BAD
 * Main work is to avoid duplicate triplets
 * But I found in the discuss that you can see that as two sum Problem
 * and using 
 * """  sort(res.begin(), res.end());
 *      res.erase(unique(res.begin(), res.end()), res.end());"""
 * Another choice is we can sort the input first
 */
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 3) return res;  
        vector<vector<int>> target(n, vector<int>(n));
        unordered_map<int, int> C, V;
        unordered_map<int, int>::iterator oit, iit;

        for(int i = 0; i < n; i++){
            if(C.find(nums[i]) == C.end())
                C.insert(make_pair(nums[i],1));
            else
                C[nums[i]]++;
			V.insert(make_pair(nums[i], i));
        }
        for( oit = C.begin(); oit!= C.end(); oit++)
            for (iit = oit; iit != C.end(); iit++){
                if(iit == oit && C[iit->first] <=1) continue;
                int target = -(oit->first + iit->first);
				// >= for [-1 -1 2] case
                if(C.find(target) != C.end() && V[target] >= V[iit->first] && V[target] >= V[oit->first])
                {
                    if( target == 0 && oit->first == 0 && oit->second < 3) continue;
                    vector<int> tmp(3, 0);
                    tmp[0] = oit->first;
                    tmp[1] = iit->first;
                    if(target == oit->first && oit->second > 1)
                        tmp[2] = oit->first;
                    else if(target == iit->first && iit->second > 1)
                        tmp[2] = iit->first;
                    else if(target == iit->first && iit->second <=1 
                            || target == oit->first && oit->second <=1)
                        continue;
                    else
                        tmp[2] = target;
					res.push_back(tmp);
                }
            }
        return res;
    }
};
