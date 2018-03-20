class Solution{
public:
    int myAtoi(string str){
        int i = 0, syl = 1;
		while(str[i] ==' ') ++i;
        if(str[i] == '+'){
            syl = 1;
            ++i;
        } 
        else if(str[i] == '-'){
            syl = -1;
            ++i;
        }
        long res = 0;
        for(; i < str.length(); ++i){
			if( str[i] > '9' || str[i] < '0') return syl * res;
            res = res * 10 + (str[i]-'0');
            if(res > INT_MAX && syl == 1) return INT_MAX;
            if(-res < INT_MIN && syl == -1) return INT_MIN;
        }
        return syl * res;
    }
};
