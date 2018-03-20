/*** Longest Substring Without REpeating Characters ***/
/*** Using Hash Table O(nlogn) ---BAD!! @_@ ***/
/*** jhonsonlaid@gmail.com ***/
/* 1. Notice str should no skip whitespace "is >> noskipws"
 * 2. Notice map's order not same as input order
 */

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        map<char, int> str_map;    
        char tmp_ch = NULL;
        int max_len = 0, len = 0;
        istringstream is(s);
        //!!! Important no skip white space
        is >> noskipws;
        while(is>>tmp_ch){
            if(str_map.find(tmp_ch)==str_map.end()){
                str_map.insert(pair<char, int>(tmp_ch, ++len));
            }
            else{
                max_len = len > max_len ? len : max_len;
                map<char, int> tmp_map(str_map);
                str_map.clear();
                len = 0;
                for(map<char, int>::iterator it=tmp_map.begin(); it!=tmp_map.end(); ++it)
                {
                    if(it->second > tmp_map[tmp_ch])    
				        //Attention the map's order is key order, if map.insert(char, ++len) will affect the
                        //sentence's order, so should be "map.insert(char, len(char)-len(tmp))"
                        str_map.insert(pair<char, int>(it->first, it->second-tmp_map[tmp_ch]));
                }
                str_map.insert(pair<char, int>(tmp_ch, len=str_map.size()+1));
            }
        }
        //case "c", "ababc"
        return len > max_len ? len : max_len;
    }
};
