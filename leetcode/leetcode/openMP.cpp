#include <iostream>
#include <time.h>
#include <omp.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void test()
{
	clock_t begin;
	begin = clock();
	int a = 0;
	for (int i = 0; i < 100000000; ++i)
	{
		a++;
	}
	//cout<<clock()-begin<<" "<<omp_get_thread_num()<<endl;
}
int main()
{
	clock_t begin = clock();
	vector<int> f(1000,0);
	vector<int> g(f);
	cout<<clock() - begin<<endl;
	int i = 0;
	//transform(f.begin(), f.end(), back_inserter(g), [&i](int& x){ return x + (++i);});
	//for (auto i:g)
	//{
	//	cout<<i<<" ";
	//}
	begin = clock();
#pragma omp parallel for
	for (int i = 0; i < 1000; ++i)
	{
		test();
		//f[i] = g[i];
		//g[min(i+222, 1000-1)] = f[i];
		//if (rand()%5 == 0)
		//{
		//	int tmp = rand() % 100000000;
		//	g[tmp] = f[i];
		//}
	}
	clock_t end = clock();
	cout<<"total time = "<<end - begin<<endl;
	//int corNum = omp_get_num_procs();
	//cout<<corNum<<endl;
}