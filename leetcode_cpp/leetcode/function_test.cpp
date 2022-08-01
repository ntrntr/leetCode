#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <tuple>

#include<vector>
using namespace std;

void function_test()
{
    std::vector<int> A{1,2,3,4,5,8, 9,10,333};
    auto fuc = std::bind(std::logical_and<bool>(),
        std::bind(std::greater<int>(), std::placeholders::_1, 5),
    std::bind(std::less<int>(), std::placeholders::_1, 10)
        );
    cout << std::count_if(A.begin(), A.end(), fuc) << endl;
    
}

void test_lambda()
{
    auto f1 = [](int a, int b) -> bool
    {
        return ((a + b) & 1) == 0;
    };
    cout << f1(1, 1) << endl;

    int aab = 3;
    auto f2 = [aab]() mutable 
    {
        aab++;
        cout << "inner aab:" << aab << endl;
    };
    f2();
    cout << aab << endl;

    tuple<int&, const char(&)[3], int&> tp = std::tie(1, "aa", 2);
}

int main(void)
{
    cout << "hello world" << endl;
    function_test();
    test_lambda();
    return 0;
}