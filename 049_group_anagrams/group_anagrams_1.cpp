class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs){
		unordered_map<string, multiset<string>> smap;
		vector<vector<string>> res;
		for (string s : strs){
			string tmp(s);
			sort(tmp.begin(), tmp.end());
			smap[tmp].insert(s);
		}
		for (auto e : smap){
			vector<string> vs(e.second.begin(), e.second.end());
			res.push_back(vs);
		}
		return res;
	}
};
