/* Time Limit Exceeded
 */
class Solution{
public:
	string getPermutation(int n, int k){
		string init, res;
		int num = 1;
		for (int i = 1; i <= n; i++){
			init.push_back(i + '0');
		}
		return helper(init, num, res, k);
	}
	string helper(string s, int& num, string res, int k){
		if (s.size() <= 0){
			if (num < k){
				num++;
				return string();
			}
			else
				return res;
		}
		for (int i = 0; i < s.size(); i++){
			string tmp(s), tmp_res(res), ret;
			tmp.erase(tmp.begin() + i);
			tmp_res.push_back(s[i]);
			ret = helper(tmp, num, tmp_res, k);
			if (!ret.empty())
				return ret;
		}
		return string();
	}
};
