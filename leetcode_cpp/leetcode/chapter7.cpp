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
	static int a[2] = { 1, 2 };
	int p = 5, p2 = 6, *page, *page2;
	int Test[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	int Test2[3] = { 1, 2, 3 };
	page = &p;
	page2 = &p2;
	int *ptr[5];
	ptr[0] = &p;
	ptr[1] = page2;
	int(*A)[3], (*B)[3];
	A = &Test[1];
	B = &Test2;
	cout << *page << endl;
	cout << (*A)[0] << (*A)[1] << (*A)[2] << endl;
	cout << (*B)[3] << endl;
	return 0;
}