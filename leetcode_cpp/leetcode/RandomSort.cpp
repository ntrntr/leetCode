#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;
bool MyCompe(const int& a, const int& b)
{
	return a < b;
}
class MyClass
{
public:

	

	void RandomSort(vector<int>& cards)
	{
		for (int i = 1; i < cards.size(); ++i)
		{
			int changeToIndx = rand() % i;
			int tmp = cards[i];
			cards[i] = cards[changeToIndx];
			cards[changeToIndx] = tmp;
		}
		sort(cards.begin(), cards.end(), MyCompe);
	}

private:

};

int main()
{
	MyClass mc;
	vector<int> test{ 1,34,5,6 };
	mc.RandomSort(test);
	for each (int var in test)
	{
		cout << var << endl;
	}
	return 0;
}
