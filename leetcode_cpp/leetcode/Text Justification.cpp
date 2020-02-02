#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		vector<string> word;
		const int n = words.size();
		int tmp = 0;
		for (int i = 0; i < n; ++i)
		{
			if (tmp + words[i].size() + word.size() > maxWidth)
			{
				//
				string s;
				int space = maxWidth - tmp;
				s = s + word[0]; 
				for (int j = 1; j < word.size(); ++j)
				{
					s = s + string( space / (word.size() - 1) + (space % (word.size() - 1) >= j ? 1:0),' ') + word[j];
				}
				if (word.size() == 1)
				{
					s = s + string(maxWidth - s.size(),' ');
				}
				res.push_back(s);
				word.clear();
				word.push_back(words[i]);
				tmp = words[i].size();
				
			}
			else
			{
				word.push_back(words[i]);
				tmp += words[i].size();
			}
			
			if (i == n-1)
			{
				//
				string s;
				int space = maxWidth - tmp;
				s = s + word[0]; 
				for (int j = 1; j < word.size(); ++j)
				{
					s = s + string( 1,' ') + word[j];
				}
				if (word.size() < maxWidth)
				{
					s = s + string(maxWidth - s.size(),' ');
				}
				res.push_back(s);
			}
		}

		return res;
	}
};
int main()
{
	Solution s;
	string a[] = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
	vector<string> tmp(a,a + 19);
	for(auto i: s.fullJustify(tmp, 30))
	{
		for (int j = 0; j < 30; ++j)
		{
			cout<<"-";
		}
		cout<<endl;
		cout<<i<<"|"<<endl;
	}
	return 0;
}