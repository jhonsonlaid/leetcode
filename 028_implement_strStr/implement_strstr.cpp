class Solution{
public:
    int strStr(string haystack, string needle){
        for(int i = 0; i < haystack.length(); i++){
            if(i + needle.length() > haystack.length()) return -1;
            int j = 0;
            while(j < needle.length() && haystack[i+j] == needle[j])
                j++;
            if(j >= needle.length()) return i;
        }
        return needle.length() ? -1 : 0;
    }
};
