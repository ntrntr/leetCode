class Solution {
public:

	double _myPow(double x, long n)
	{
		if (n == 1)
		{
			return x;
		}

		if (n % 2 == 0)
		{
			auto r = _myPow(x, n / 2);
			return r * r;
		}
		else
		{
			auto r = _myPow(x, (n - 1) / 2);
			return x * r * r;
		}
	}

	double myPow(double x, int n) {
		if (n == 0)
		{
			return 1;
		}
		else if (n < 0)
		{
			return 1.0 / _myPow(x, -static_cast<long int>(n));
		}
		else
		{
			return _myPow(x, n);
		}
	}
};

int main(void)
{
	return 0;
}