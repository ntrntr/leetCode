#include <stdio.h>
class test
{
public:
	test(const char* p);
	test(int in);
	const char* operator() const {
		return
			data.ch;
	}
	operator long() const { return data.i; }
private:
	enum type { Int, String };
	union datatype
	{
		const char* ch;
		int i;
	}data;
	type stype;
	test(test&);
	test& operator=(const test&);
};
test::test(const char *p) :stype
(String) { }
test::test(int in) : stype(Int) {
}

int main()
{
	return 0;
}