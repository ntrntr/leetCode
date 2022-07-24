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

vector<int> arr = {4,3,5,2,0};

vector<int>& get_range()
{
    return arr;
}

void range_test()
{
    for(auto val:get_range())
    {
        cout << val << endl;
    }
}
namespace detail_range
{
template <typename T>
class iterator
{
public:
    using value_type = T;
    using size_type = size_t;
    iterator(size_type cur_start, value_type begin_val, value_type step_val): cursor_(cur_start),
    step_(step_val),
    value_(begin_val)
    {
        value_ += (step_ * cursor_);
    }
    value_type operator*() const
    {
        return value_;
    }
    bool operator!=(const iterator& rhs) const
    {
        return cursor_ != rhs.cursor_;
    }
    iterator& operator++(void)
    {
        value_ += step_;
        ++cursor_;
        return *this;
    }

private:
    size_type cursor_;
    const value_type step_;
    value_type value_;
};

template <typename T>
class impl
{
public:
    using value_type = T;
    using reference = const value_type&;
    using const_reference = const value_type&;
    using iterator = const detail_range::iterator<value_type>;
    using const_iterator = const detail_range::iterator<value_type>;
    using size_type = typename iterator::size_type;

    impl(value_type begin_val, value_type end_val, value_type step_val):
        begin_(begin_val),
        end_(end_val),
        step_(step_val),
        max_count_(get_adjusted_count())
    {

    }

    size_type size() const
    {
        return max_count_;
    }
    const_iterator begin() const
    {
        return {0, begin_, step_};
    }
    const_iterator end() const
    {
        return {max_count_, begin_, step_};
    }

    

private:
    const value_type begin_;
    const value_type end_;
    const value_type step_;
    const size_type max_count_;

    size_type get_adjusted_count() const
    {
        if (step_ > 0 && begin_ >= end_)
        {
            throw std::logic_error("end value max greater than begin value");
        }
        if (step_ < 0 && begin_ <= end_)
        {
            throw std::logic_error("end value max less than begin value");
        }
        size_type x = static_cast<size_type>((end_-begin_)/step_);
        if (begin_ + (step_ * x) != end_)
        {
            x++;
        }
        return x;
    }
};


}

template <typename T>
detail_range::impl<T> range(T end)
{
    return {{}, end, 1};
}

template <typename T>
detail_range::impl<T> range(T begin, T end)
{
    return {begin, end, 1};
}

template <typename T, typename U>
auto range(T begin, T end, U step) -> detail_range::impl<decltype(begin + step)>
{
    using return_type = detail_range::impl<decltype(begin + step)>;
    return return_type(begin, end, step);
}


int main(void)
{
    const int& a = 0;
    // decltype(a) b;
    
    cout << "type is:" << typeid(a).name() << endl;
    // foreach_test();
    range_test();
    return 0;
}