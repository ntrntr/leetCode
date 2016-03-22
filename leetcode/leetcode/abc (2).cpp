#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
string mars[25] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
	"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
//分别存储0-12以及13的1到12倍
string earth2mars(int x){
	if (x / 13 == 0){
		return mars[x];
	}
	else if (x % 13 == 0){
		return mars[12 + x / 13];
	}
	else{
		return mars[12 + x / 13] + " " + mars[x % 13];
	}
}
int mars2earth(string x){
	int ge = 0, shi = 0;
	int idx = x.find(" ");//查找有没有空格
	if (idx == string::npos){//没有空格，只有一个数
		for (int i = 0; i < 25; ++i){
			if (mars[i] == x){
				if (i <= 12)ge = i;//是个位的情况
				else shi = i - 12;//是十位的情况
				break;
			}
		}
	}
	else{
		string shi_str = x.substr(0, idx);//提取出火星文十位的部分
		string ge_str = x.substr(idx + 1, x.size() - idx);//提取出火星文个位的部分
		for (int i = 0; i < 13; ++i){
			if (mars[i] == ge_str){
				ge = i;//是个位的情况
				break;
			}
		}
		for (int i = 13; i < 25; ++i){
			if (mars[i] == shi_str){
				shi = i - 12;//是个位的情况
				break;
			}
		}
	}
	return ge + shi * 13;
}
int main(){
	//freopen("D://input.txt", "r", stdin);
	int n;
	cin >> n;
	getchar();//获取最后的回车符，因为后面是getline
	string str;
	while (n--){
		getline(cin, str);//获取整行
		if (str[0] <= '9' && str[0] >= '0'){//是地球文
			cout << earth2mars(atoi(str.c_str())) << endl;
		}
		else{//是火星文
			cout << mars2earth(str) << endl;
		}
	}
	return 0;
}