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

    // tuple<int&, const char(&)[3], int&> tp = std::tie(1, "aa", 2);
}

int g_construct = 0;
int g_copy = 0;
int g_assign = 0;

class TestA
{
public:
    TestA()
    {
        cout << "construct:" << ++g_construct << endl;
    }

    ~TestA()
    {
        cout << "deconstruct:" << endl;
    }

    TestA(const TestA& Other)
    {
        cout << "g_copy:" << ++g_copy << endl;


    }

    TestA(TestA&& Other) noexcept
    {
        cout << "g_copy RValueRefrence:" << ++g_copy << endl;
    }

    TestA& operator=(const TestA& Other)
    {
        if (this == &Other)
            return *this;
        cout << "g_assign:" << ++g_assign << endl;
        return *this;
    }

    TestA& operator=(TestA&& Other) noexcept
    {
        if (this == &Other)
            return *this;
        cout << "g_assign RValueRefrence:" << ++g_assign << endl;

        return *this;
    }
};

void test_r_value_reference()
{
    TestA a = TestA();
    
}

int main(void)
{
    cout << "hello world" << endl;
    function_test();
    test_lambda();
    test_r_value_reference();
    return 0;
}