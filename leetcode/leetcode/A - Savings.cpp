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
	int n,x;
	cin>>n>>x;
	int res = (n % x == 0? (n / x) : (n / x + 1));
	cout<<res<<endl;
	return 0;
}