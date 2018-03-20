/*** Longest Substring Without REpeating Characters ***/
/*** jhonsonlaid@gmail.com ***/

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        map<char, int> str_map;
        int start = -1, max_len = 0;
        for(int i=0; i<s.length(); ++i){
            if(str_map.find(s[i]) != str_map.end())
                start = str_map[s[i]] > start ? str_map[s[i]] : start;
            str_map[s[i]] = i;
            max_len = max(max_len, i-start);
        }
    return max_len;
    }
};
