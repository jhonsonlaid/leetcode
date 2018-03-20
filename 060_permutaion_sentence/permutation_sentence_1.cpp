/* solve TLE by check if num + inc >= k
 * to reduce recursive time
 */
class Solution{
private:
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
			int inc = 1;
			for (int j = 1; j < s.size(); j++){
				inc *= j;
			}
			if (num + inc >= k){
				ret = helper(tmp, num, tmp_res, k);
				if (!ret.empty())
					return ret;
			}
			else{
				num = num + inc;
			}
			
		}
		return string();
	}

public:
	string getPermutation(int n, int k){
		string init, res;
		int num = 1;
		for (int i = 1; i <= n; i++){
			init.push_back(i + '0');
		}
		return helper(init, num, res, k);
	}
};
