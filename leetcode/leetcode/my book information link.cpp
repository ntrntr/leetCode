#include<stdio.h>
#include"stdlib.h"
#include"string.h"
using namespace std;

struct node
{
	node(){}
	char no[10];
	char name[20];
	char writer[20];
	char publisher[30];
	int  date,price,amount;
	struct Lnode *next;
};

int main()
{
	return 0;
}