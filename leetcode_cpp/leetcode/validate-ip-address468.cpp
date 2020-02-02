#include <string>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool checkIPV4(const basic_string<char>& IP)
	{
		vector<string> datas;
		datas.clear();
		split(IP, ".", datas);
		if (datas.size() == 4)
		{
			for (const basic_string<char> cs : datas)
			{
				if (!checkIPV4Group(cs))
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool checkIPV4Group(const basic_string<char>& data)
	{
		if (data.size() >  3 || data.size() == 0)
		{
			return false;
		}
		for (int i = 0; i < data.size(); ++i)
		{
			if (!(data[i] >= '0' && data[i] <= '9'))
			{
				return false;
			}
		}

		// zero head
		if (data.size() > 1 && data[0] == '0')
		{
			return false;
		}

		int ret = std::stoi(data);

		return ret >= 0 && ret <= 255;
	}

	bool checkIPV6Group(const string& cs)
	{
		string data = cs;
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		if (data.size() >  4 || data.size() == 0)
		{
			return false;
		}
		for (int i = 0; i < data.size(); ++i)
		{
			if (!((data[i] >= '0' && data[i] <= '9') || (data[i] >= 'a' && data[i] <= 'f')))
			{
				return false;
			}
		}

		return true;
	}

	bool checkIPV6(const basic_string<char>& IP)
	{
		vector<string> datas;
		datas.clear();
		split(IP, ":", datas);
		if (datas.size() == 8)
		{
			for (const basic_string<char> cs : datas)
			{
				if (!checkIPV6Group(cs))
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	string validIPAddress(std::string IP) {
		
		if (checkIPV4(IP))
		{
			return IPV4;
		}
		if (checkIPV6(IP))
		{
			return IPV6;
		}
		return NEITHER;
	}

	void split(const string& s,const string& delim, vector<string>& ret)
	{
		size_t pos1, pos2;
		pos2 = s.find(delim);
		pos1 = 0;
		while (pos2 != string::npos)
		{
			ret.push_back(s.substr(pos1, pos2 - pos1));
			pos1 = pos2 + delim.size();
			pos2 = s.find(delim, pos1);
		}
		if (pos1 != s.length())
		{
			ret.push_back(s.substr(pos1));
		}
		else
		{
			if (pos2 == string::npos)
			{
				ret.push_back("");
			}
		}
	}
public:
	static  string IPV4;
	static  string IPV6;
	static  string NEITHER;
};

string Solution::IPV4 = "IPv4";
string Solution::IPV6 = "IPv6";
string Solution::NEITHER = "Neither";
int main(int argc, char* argv[])
{
	Solution s;
	_ASSERT(s.validIPAddress("172.16.254.1") == Solution::IPV4);
	_ASSERT(s.validIPAddress("256.256.256.256") == Solution::NEITHER);
	_ASSERT(s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") == Solution::IPV6);
	_ASSERT(s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") == Solution::NEITHER);
	return 0;	
}
