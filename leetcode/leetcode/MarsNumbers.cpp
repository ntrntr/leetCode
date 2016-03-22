#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	//1-12
	const string num[] = {"tret","jan" , "feb" , "mar" , "apr" , "may" , "jun" , "jly" , "aug" , "sep" , "oct" , "nov" , "dec"};
	const string higherNum[] = {"", "tam" , "hel" , "maa" , "huh" , "tou" , "kes" , "hei" , "elo" , "syy" , "lok" ,"mer" ,"jou"};
	map<string, string> numToChar;
	map<string, string> charToNum;
	for (int i = 0; i < 169; ++i)
	{
		char tmp[20];
		int a = i / 13;
		int b = i % 13;
		if (a == 0)
		{
			
			sprintf(tmp, "%d", i);
			numToChar.insert(make_pair(tmp , num[b]));
			charToNum.insert(make_pair( num[b], tmp ));
		}
		else if (b == 0 && a != 0)
		{
			sprintf(tmp, "%d", i);
			numToChar.insert(make_pair(tmp, higherNum[a]));
			charToNum.insert(make_pair( higherNum[a], tmp ));
		}
		else
		{
			sprintf(tmp, "%d", i);
			numToChar.insert(make_pair(tmp , higherNum[a] + " " + num[b]));
			charToNum.insert(make_pair( higherNum[a] + " " + num[b], tmp ));
		}
			 
			
		
		
	}
	int n;
	cin>>n;
	getchar();
	while (n--)
	{
		char *s = new char[20];
		cin.getline(s, 20);
		if (s[0] >= '0' && s[0] <= '9')
		{
			if (numToChar.find(s) != numToChar.end())
			{
				cout<<numToChar[s]<<endl;
			}
		}
		else
		{
			if (charToNum.find(s) != charToNum.end())
			{
				cout<<charToNum[s]<<endl;
			}
			else
				cout<<"0"<<endl;
		}
		}

	return 0;
}