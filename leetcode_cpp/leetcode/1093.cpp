#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main1()
{
	string s;
	cin>>s;
	const int size = s.size();
	vector<int> T(size + 1, 0);
	vector<int> AT(size + 1, 0);
	long int count = 0;
	for (int i = size - 1; i >= 0; --i)
	{
		if (s[i] == 'T')
		{
			T[i] = T[i + 1] + 1;
			AT[i] = AT[i + 1];
		}
		if (s[i] == 'A')
		{
			T[i] = T[i + 1];
			AT[i] = AT[i + 1] + T[i];
		}
		if (s[i] == 'P')
		{
			T[i] = T[i + 1];
			AT[i] = AT[i + 1];
			count += AT[i];
		}
	}
	cout<<count % 1000000007<<endl;
	return 0;
}