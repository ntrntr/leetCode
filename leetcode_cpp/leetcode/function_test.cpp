#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

#include<vector>
using namespace std;

template <class T>
std::string
type_name()
{
    using TR = std::remove_reference<T>::type;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

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
    // TestA a = TestA();
    int x = 10;
    auto&& var1 = x;
    cout << type_name<decltype(var1)>() << endl;
    cout << type_name<decltype(x)>() << endl;
    cout << type_name<decltype((x))>() << endl;
}

void test_r_value2()
{
    int w1, w2;
    auto&& c1 = w1;
    decltype(w1)&& c2 = std::move(w2);
    cout << type_name<decltype(c2)>() << endl;
    cout << type_name<decltype(c1)>() << endl;

}

template<typename T>
void Func(T&& t)
{
    cout << type_name<T>() << endl;
}
class Foo{};
int main(void)
{
    cout << "hello world" << endl;
    // function_test();
    // test_lambda();
    // test_r_value2();
    
    // string test = "Test";
    // Func(test);
    // Func(move(test));
    
    // class Foo {};
    cout << typeid(Foo*[10]).name() << endl;
    return 0;
}