class Solution {
public:
    string smallestGoodBase(string n) {
        auto tn = static_cast<unsigned long long>(stoll(n));
        unsigned long long x = 1;
        for(auto i=62; i >= 1; i--)
        {
            if ((x << i) < tn)
            {
                auto ret = solveWithD(tn, i);
                if(ret != 0)
                {
                    return to_string(ret);
                }
            }
        }
        return to_string(tn-1);
    }
    unsigned long long solveWithD(unsigned long long expect_value, int expect_len)
    {
        auto right_bound = static_cast<unsigned long long>(pow(static_cast<double>(expect_value), 1.0/expect_len)) + 1;
        auto left_bound = static_cast<unsigned long long>(1);
        while(left_bound <= right_bound)
        {
            auto mid = left_bound + (right_bound - left_bound) / 2;
            unsigned long long sum = 1, cur = 1;
            for(auto i=1; i <= expect_len; ++i)
            {
                cur *= mid;
                sum += cur;
            }
            if (sum == expect_value) return mid;
            if (sum > expect_value)
            {
                right_bound = mid - 1;
            }
            else
            {
                left_bound = mid + 1;
            }
        }
        
        return 0;
    }
};