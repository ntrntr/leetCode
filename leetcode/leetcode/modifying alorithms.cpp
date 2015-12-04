#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <functional>
#include <time.h>
#include <numeric>
using namespace std;
clock_t tictime;
template<typename T>
void insertElem(T& v, int first, int last)
{
	for (int i = first; i <= last; ++i)
	{
		v.insert(v.end(), i);
	}
}

template<typename T>
void printElem(T& v)
{
	for (auto i:v)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}
class Solution
{
public:
	Solution(){};
	~Solution(){};
protected:
	
private:
};
void tic()
{
	tictime = clock();
}
void toc()
{
	cout<<"time esplaced = "<<clock() - tictime <<endl;
}
int main()
{
	Solution ss;
	vector<int> s;
	insertElem(s, 1,6);
	random_shuffle(s.begin(), s.end());
	printElem(s);
	adjacent_difference(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}