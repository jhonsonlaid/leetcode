/* sort() takes O(nlogn) time
 * but here we only need sort letters
 * getkey takes O(n) time
 */
class Solution{
private:
	string getkey(string s){
		int count[26] = { 0 };
		for (auto e : s){
			count[e - 'a']++;
		}
		string res;
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < count[i]; j++){
				res.push_back(i + 'a');
			}
		}
		return res;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs){
		unordered_map<string, multiset<string>> smap;
		vector<vector<string>> res;
		for (auto s: strs){
			string skey = getkey(s);
			smap[skey].insert(s);
		}
		for (auto e : smap){
			vector<string> vs(e.second.begin(), e.second.end());
			res.push_back(vs);
		}
		return res;
	}
};
