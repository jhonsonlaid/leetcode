class Solution {
public:
    string multiply(string num1, string num2){
        int len1 = num1.length(), len2 = num2.length();
		string res;
        for(int i = len1 - 1; i >= 0; i--){
            int extra = 0;
            string step_res;
            for(int j = len2 - 1; j >= 0; j--){
				int n1 = num1[i] - '0';
				int n2 = num2[j] - '0';
                int sum = n1 * n2 + extra;
                step_res = to_string(sum % 10) + step_res;
                extra = sum / 10;
            }
			if (extra != 0)
				step_res = to_string(extra) + step_res;
			for (int k = 0; k < len1 - 1 - i; k++)
				step_res = step_res + "0";
			res = add(step_res, res);
        }

		int i0 = 0;
		for (; i0 < res.length() - 1 && res[i0] == '0'; i0++);
		res = res.substr(i0);

		return res;
    }

	string add(string num1, string num2){
		int len1 = num1.length(), len2 = num2.length();
		if (len1 < len2) return add(num2, num1);
		string res;
		for (int i = 0; i < len1 - len2; i++)
			num2 = "0" + num2;
		int extra = 0;
		for (int i = len1 - 1; i >= 0; i--){
			int n1 = num1[i]  -'0';
			int n2 = num2[i]  -'0';
			int sum = n1 + n2 + extra;
			res = to_string(sum % 10) + res;
			extra = sum / 10;
		}
		if (extra != 0)
			res = to_string(extra) + res;
		return res;
	}
};
