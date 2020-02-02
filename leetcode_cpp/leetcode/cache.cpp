#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	//vector<string> cache;
	deque<string> cache;
	cin>>n>>m;
	string tmp;
	while (n--)
	{
		cin>>tmp;
		auto it = find(cache.begin(),cache.end(), tmp);
		if (it != cache.end())
		{
			cache.erase(it);
			cache.push_front(tmp);
			cout<<"Cache"<<endl;
		}
		else
		{
			if (cache.size() < m)
			{
				cache.push_front(tmp);
			}
			else
			{
				cache.pop_back();
				cache.push_front(tmp);
			}
			cout<<"Internet"<<endl;
			
		}
	}
	return 0;
}