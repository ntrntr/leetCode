#include <iostream>
#include <string>
#include <algorithm>

#include<vector>
using namespace std;

void test1()
{
    int a = 1.1;
    // int b = {1.1};
    float ff = 1.2f;
    float fd = {1.2};
    cout << a << ff << fd;
}

void foreach_test()
{
    vector<int> aa{1,2,4,2,4};
    for_each(aa.begin(), aa.end(), [](int value){ cout << value << endl;});
}

int main(void)
{
    const int& a = 0;
    // decltype(a) b;
    
    cout << "type is:" << typeid(a).name() << endl;
    foreach_test();
    return 0;
}