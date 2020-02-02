#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <limits.h>
using namespace std;
int main()
{
	int a1, b1, c1, a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int r1, r2, r3;
	int jinwei = 0;
	r3 = (c1 + c2) % 29;
	jinwei = (c1 + c2) / 29;
	r2 = (b1 + b2 + jinwei) % 17;
	jinwei = (b1 + b2 + jinwei) / 17;
	r1 = (a1 + a2 + jinwei) % 100000001;
	cout << r1 << "." << r2 << "." << r3 << endl;
	return 0;
}