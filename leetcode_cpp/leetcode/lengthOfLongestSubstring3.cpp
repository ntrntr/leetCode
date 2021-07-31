#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        auto ssize = (int)s.size();
        if(ssize <= 1)
        {
            return ssize;
        }
        int ret = 1;
        map<char, int> _map;
        int last_del_index = -1;
        for (int i=0; i < ssize; ++i)
        {
            auto v = s[i];
            auto iter = _map.find(v);
            if(iter == _map.end())
            {
                _map[v] = i;
                ret = max(ret, (int)_map.size());
            }
            else
            {
                auto aa = iter->second;
                for(auto j=last_del_index+1; j <= aa; ++j)
                {
                    _map.erase(s[j]);
                }
                last_del_index = aa;
                _map[v] = i;
                ret = max(ret, (int)_map.size());
            }
        }
        return ret;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto ssize = (int)s.size();
        if(ssize <= 1)
        {
            return ssize;
        }
        int ret = 1;
        unordered_map<char, int> _map;
        int last_del_index = -1;
        int map_current_size = 0;
        for (int i=0; i < ssize; ++i)
        {
            auto v = s[i];
            auto iter = _map.find(v);
            if(iter == _map.end())
            {
                _map[v] = i;
                map_current_size++;
                ret = max(ret, map_current_size);
            }
            else
            {
                auto aa = iter->second;
                for(auto j=last_del_index+1; j <= aa; ++j)
                {
                    _map.erase(s[j]);
                    map_current_size--;
                }
                last_del_index = aa;
                _map[v] = i;
                map_current_size++;
                ret = max(ret, map_current_size);
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}