#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <time.h>
#include <functional>
#include <set>
#include <sstream>
#include <iostream>
#include <ostream>
using namespace std;
template<typename T>
class BetweenValues:
	public unary_function<T, bool>
{
public:
	BetweenValues(const T& lowvalue, const T& highvalue):lowval(lowvalue), highval(highvalue){};
	bool operator()(const T& val) const
	{
		return val > lowval && val < highval;
	}
private:
	T lowval;
	T highval;
};
inline bool intgreater(int x, int y)
{
	return x > y;
}
struct stringsize:
	public unary_function<string, string::size_type>
{
	string::size_type operator()(const string& s) const
	{

		return s.size();
	}
};
struct mycomp:
	public binary_function<string, string, bool>
{
	bool operator() (const string& lhs, const string& rhs) const
	{
		return lhs.size()> rhs.size();
	}
};
int main()
{
	//fstream inputfile("stdafx.cpp");
	//string filedata((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
	//cout<<filedata<<endl;
	//cout<<filedata.size()<<endl;
	//cout<<filedata.length()<<endl;
	//vector<int> values(10, 1);
	//vector<int> res;
	//list<int> ilist;
	//int i = 0;
	//transform(values.begin(), values.end(), back_inserter(res), [&i](int& x)
	//{
	//	++i;
	//	return x+i;
	//});
	//i = 1;
	//transform(values.begin(), values.end(), inserter(ilist,next(ilist.begin(), ilist.size() / 2) ), [&i](int& x)
	//{
	//	i *= 2;
	//	return x * i;
	//});
	//for (auto i:ilist)
	//{
	//	cout<<i<<" ";
	//}
	//vector<int> f;
	//for (int i = 0; i < 1000000; ++i)
	//{
	//	f.push_back(rand());
	//}
	//for (int i = 0; i < 100; ++i)
	//{
	//	cout<<f[i]<<" ";
	//}
	//cout<<endl;
	//vector<int> g(f);
	//vector<int> h(f);
	//time_t begin, end;
	//begin = clock();
	//sort(f.begin(), f.end(), greater<int>());
	//end = clock();
	//cout<<end - begin <<endl;
	//begin = clock();
	//sort(g.begin(), g.end(), intgreater);
	//end = clock();
	//cout<<end - begin <<endl;
	//begin = clock();
	//sort(h.begin(), h.end(), [](int x, int y){return  x > y;});
	//end = clock();
	//cout<<end - begin <<endl;
	//for (int i = 0; i < 100; ++i)
	//{
	//	cout<<f[i]<<" ";
	//}
	//cout<<endl;
	//set<string, mycomp> s;
	//stringstream ss;
	//string st;
	//for (int i = 0; i < 26; ++i)
	//{
	//	st += ('a' + i);
	//	s.insert(st);
	//}
	//for(auto i:s)
	//{
	//	cout<<i<<" ";
	//}
	//cout<<endl;
	//transform(s.begin(), s.end(), ostream_iterator<string::size_type>(cout, "caonima\n"), stringsize());
	vector<int> f;
	for (int i = 0; i < 10; ++i)
	{
		f.push_back(rand() % 10);
	}
	for (auto i:f)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	f.erase(
		remove_if(
		find_if(f.rbegin(), f.rend(), bind2nd(greater_equal<int>(),8)).base(),
		f.end(),
		bind2nd(less<int>(), 3)
		),
		f.end());
	for (auto i:f)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	string s(10);

	return 0;
}