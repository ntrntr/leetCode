#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int, int> mymap;
	int tmp;
	int res = -1;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp;
		if ((++mymap[tmp]) >= (n / 2 + 1))
		{
			res = tmp;
		}
		
		
	}
	if (res == -1)
	{
		cout<<"?"<<endl;
	}
	else
		cout<<res<<endl;
	return 0;
}