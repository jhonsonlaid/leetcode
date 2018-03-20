class Solution{
public:
    int strStr(string haystack, string needle){
        for(int i = 0; i < haystack.length(); i++){
            if(i + needle.length() > haystack.length()) return -1;
            for(int j = 0; j < needle.length() && haystack[i+j] == needle[j]; j++)
                if(j == needle.length()-1) return i;
        }
        return needle.length() ? -1 : 0;
    }
};
