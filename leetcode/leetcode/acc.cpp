#include<iostream>   
#include<string>  
using namespace std;
int equelstr(string *mars, string str)
{
	int i;
	for (i = 0; i < 25 && mars[i] != str; i++);
	return i;
}
int main1()
{
	string mars[25] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
		"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	string str,strt;
	int N, num,temp,goal; 
	cin >> N;
	getchar();
	while (N--)
	{
		getline(cin, str);  
		if (str[0] >= '0'&&str[0] <= '9' ) 
		{
			sscanf(str.c_str(), "%d", &num); 
			if (num < 13 || num>12 && num % 13 == 0)
				cout << mars[num%13+(num>12?num/13+12:0)] << endl;
			else 
				cout << mars[num / 13+12] << " " << mars[num % 13] << endl; 
		}
		else 
		{
			temp = str.find(' ');
			if (temp != -1)
			{ 
				strt = str.substr(0,3);  
				goal = (equelstr(mars, strt)-12)*13;
				strt = str.substr(temp+1,3); 
				goal += equelstr(mars, strt);
			}
			else
			{
				goal=equelstr(mars, str);
				goal = goal > 12 ? (goal - 12) * 13 : goal;
			} 
			cout << goal << endl; 
		}
	}
	system("pause");
	return 0;
}