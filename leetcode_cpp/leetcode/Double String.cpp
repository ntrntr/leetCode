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
	string s;
	cin>>s;
	string res(s);
	res += res;
	sort(res.begin(), res.end());
	while (next_permutation(res.begin(), res.end()))
	{
		//judge if res is a word
		cout<<res<<endl;
		return 0;

	}
	cout<<res<<endl;
	return 0;
}