#include <string>
using namespace std;
class Solution {
public:
	inline bool CheckValid(const string& tmp, const string& cs)
	{
		bool ret = true;
		int len = tmp.size();
		for (int i = len; i < cs.length() && ret; i+= len)
		{
			for (int j = 0; j < len; ++j)
			{
				if (tmp[j] != cs[i + j])
				{
					ret = false;
					break;
				}
			}
		}
		return ret;
	}

	bool repeatedSubstringPattern(std::string s) {
		if (CheckAllSame(s))
		{
			return true;
		}
		bool ret = false;
		int len = s.size();
		std::string tmp;
		for (int i = 2; i <= len / 2 && !ret; ++i)
		{
			if (len % i != 0)
			{
				continue;
			}
			tmp = s.substr(0, i);
			ret |= CheckValid(tmp, s);
		}

		return ret;
	}

	bool CheckAllSame(const string& s)
	{
		int ret = true;
		if (s.size() <= 1)
		{
			ret = false;
		}
		else
		{
			for (int i = 1; i < s.size(); ++i)
			{
				if (s[i-1] != s[i])
				{
					ret = false;
					break;
				}
			}
		}
		return ret;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	_ASSERTE(s.repeatedSubstringPattern("aaaa") == true);
	_ASSERTE(s.repeatedSubstringPattern("abab") == true);
	_ASSERTE(s.repeatedSubstringPattern("aba") == false);
	_ASSERTE(s.repeatedSubstringPattern("abcabcabcabc") == true);
	return 0;
}


