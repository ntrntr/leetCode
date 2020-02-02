#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	vector<int> f(128,0);
	//cout<<s1<<endl<<s2;
	for (int i = 0; i < s1.size(); ++i)
	{
		++f[s1[i]];
	}
	int need = 0;
	for (int i = 0; i < s2.size(); ++i)
	{
		if ((--f[s2[i]]) < 0)
		{
			++need;
		}
	}
	if (need > 0)
	{
		cout<<"No"<<" "<<need<<endl;
	}
	else
	{
		cout<<"Yes"<<" "<<s1.size() - s2.size()<<endl;
	}
	return 0;
}