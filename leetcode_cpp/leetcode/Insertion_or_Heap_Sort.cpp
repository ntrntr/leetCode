#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprintf(vector<int>& num)
{
	for (auto it:num)
	{
		cout<<it<<" ";
	}
	cout<<endl;
}
bool comp(const int& a, const int& b)
{
	return a < b;
}
int main()
{
	const int s[] = {3,1, 2, 8, 7, 5, 9, 4, 6, 0};
	vector<int> num(s, s + 10);
	myprintf(num);
	make_heap(num.begin(), num.end(), comp);
	myprintf(num);
	num.push_back(10);
	push_heap(num.begin(), num.end(), comp);
	myprintf(num);
	pop_heap(num.begin(), num.end(), comp);
	myprintf(num);
	make_heap(num.begin(), num.end(), comp);
	myprintf(num);
	sort_heap(num.begin(), num.end(), comp);
	myprintf(num);
	return 0;
}