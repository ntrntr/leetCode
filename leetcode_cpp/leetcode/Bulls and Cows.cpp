#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
	string getHint(string secret, string guess) {
		int a = 0;
		int b = 0;
		map<int, int> mmap;
		const int len = secret.length();
		for(int i = 0;i < len; ++i)
		{
			mmap[secret[i]]++;
		}
		for(int i = 0;i < len; ++i)
		{
			if(secret[i] == guess[i])
			{
				a++;
				mmap[secret[i]]--;
				if (mmap[secret[i]]<0)
				{
					b--;
				}
			}
			else if(mmap.find(guess[i]) != mmap.end() && mmap[guess[i]]-- > 0)
			{
				b++;
			}

		}
		stringstream os;
		os<<a<<"A"<<b<<"B";
		string res;
		os>>res;
		return res;
	}
};
int main()
{
	Solution s;
	cout<<s.getHint("1122","1222");
	return 0;
}