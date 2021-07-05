#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string largestOddNumber(string num) {
		auto str_len = num.length();
		auto ret = "";
		if(str_len <= 0)
		{
			return ret;
		}
		auto last_index = static_cast<int>(str_len - 1);
		while (last_index >= 0)
		{
			const auto c = num[last_index] - '0';
			if(c % 2 != 0)
			{
				break;
			}
			last_index -= 1;
		}
		if(last_index < 0)
		{
			return ret;
		}
		return num.substr(0, last_index + 1);
		

	}
};


int main(void)
{
	auto s = Solution();
	cout << s.largestOddNumber("35427") << endl;
	return 0;
}