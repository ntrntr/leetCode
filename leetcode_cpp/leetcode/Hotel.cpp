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
	vector<int> room(n);
	vector<int> customer(m);
	for (int i = 0; i < n; ++i)
	{
		cin>>room[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>customer[i];
	}
	//sort(room.begin(), room.end(),[](int x, int y){ return x > y});
	if (m > n)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sort(room.rbegin(), room.rend());
	sort(customer.rbegin(), customer.rend());
	for (int i = 0; i < m; ++i)
	{
		if (customer[i] > room[i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	//reverse(room.begin(), room.end());
	//reverse(room.begin(), room.end());
	cout<<"YES"<<endl;
	return 0;
}