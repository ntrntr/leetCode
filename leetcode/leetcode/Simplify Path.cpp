#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		vector<string> h;
		if (*prev(path.end()) != '/')
		{
			path.push_back('/');
		}
		string tmp = "";
		for (int i = 1; i < path.size(); ++i)
		{
			
			if (path[i] != '/')
			{
				tmp.push_back(path[i]);

			}
			else
			{ 
				if (tmp.size() == 0 || tmp == ".")
				{

				}

				else if (tmp == "..")
				{
					if (!h.empty())
					{
						h.pop_back();
					}
					
				}
				else 
				{
					h.push_back(tmp);
				}
				tmp = "";
				
			}



		}
		
		if (h.size() == 0)
		{
			return "/";
		}
		string res = "";
		for (auto i:h)
		{
			res += "/" + i;
		}
		return res;
	}
};
int main()
{
	Solution s;
	string tmp;
	while (cin>>tmp)
	{
		cout<<s.simplifyPath(tmp)<<endl;

	}
	return 0;
}