#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
inline void myPrint(vector<int>& ivec)
{
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
}
int main()
{
	int a[] = {15, 2, 6, 1, 55, 33};
	vector<int> ivec(a, a + 6);
	cout<<"print:"<<endl;
	myPrint(ivec);

	make_heap(ivec.begin(), ivec.end());
	cout<<"makeheap"<<endl;
	myPrint(ivec);
	pop_heap(ivec.begin(), ivec.end());
	cout<<"pop_heap"<<endl;
	myPrint(ivec);
	ivec.pop_back();
	cout<<"vector pop back()"<<endl;
	myPrint(ivec);
	
	pop_heap(ivec.begin(), ivec.end());
	myPrint(ivec);
	ivec.pop_back();
	myPrint(ivec);
	ivec.push_back(99);
	cout<<"ivec.push_back(99);"<<endl;
	push_heap(ivec.begin(), ivec.end());
	myPrint(ivec);
	sort_heap(ivec.begin(), ivec.end());
	myPrint(ivec);
	return 0;
}