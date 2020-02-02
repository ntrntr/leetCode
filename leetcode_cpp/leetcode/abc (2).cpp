#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
string mars[25] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
	"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
//�ֱ�洢0-12�Լ�13��1��12��
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
	int idx = x.find(" ");//������û�пո�
	if (idx == string::npos){//û�пո�ֻ��һ����
		for (int i = 0; i < 25; ++i){
			if (mars[i] == x){
				if (i <= 12)ge = i;//�Ǹ�λ�����
				else shi = i - 12;//��ʮλ�����
				break;
			}
		}
	}
	else{
		string shi_str = x.substr(0, idx);//��ȡ��������ʮλ�Ĳ���
		string ge_str = x.substr(idx + 1, x.size() - idx);//��ȡ�������ĸ�λ�Ĳ���
		for (int i = 0; i < 13; ++i){
			if (mars[i] == ge_str){
				ge = i;//�Ǹ�λ�����
				break;
			}
		}
		for (int i = 13; i < 25; ++i){
			if (mars[i] == shi_str){
				shi = i - 12;//�Ǹ�λ�����
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
	getchar();//��ȡ���Ļس�������Ϊ������getline
	string str;
	while (n--){
		getline(cin, str);//��ȡ����
		if (str[0] <= '9' && str[0] >= '0'){//�ǵ�����
			cout << earth2mars(atoi(str.c_str())) << endl;
		}
		else{//�ǻ�����
			cout << mars2earth(str) << endl;
		}
	}
	return 0;
}