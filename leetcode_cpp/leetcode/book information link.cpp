#include<stdio.h>
#include"stdlib.h"
#include"string.h"
#include <iostream>
#define list_init_size 100
using namespace std;
typedef struct Lnode
{ 
	char no[10];
	char name[20];
	char writer[20];
	char publisher[30];
	int  date,price,amount;
	struct Lnode *next;
}LINK;
typedef LINK *PNODE;
void main()
{ 
	FILE *fp;
	char filename[16]="E:\\book.txt";            /*运行前，请将文件存在E盘下。*/
	PNODE head,p;
	int count=0,i;
	if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	head=(PNODE)malloc(sizeof(LINK));
	strcpy(head->no,"");
	strcpy(head->name,"");
	strcpy(head->writer,"");
	strcpy(head->publisher,"");
	head->next=NULL;
	head->date=head->price=head->amount=0;
	while(!feof(fp))
	{
		p=(PNODE)malloc(sizeof(LINK));
		if (fscanf(fp,"%s %s %s %s %d %d %d",p->no,p->name,p->writer,p->publisher,&p->date,&p->price,&p->amount)==7)
		{
			count++;
			p->next=head->next;
			head->next=p;
		}
		
	}
	p=head->next;
	for(int i = count;i>0;i--) 
	{
		printf("%s %s %s %s %d %d %d\n" ,p->no,p->name,p->writer,p->publisher,p->date,p->price,p->amount);
		p=p->next;
	}
	char cmd[10];
	//有二种操作， insert和delete
	//insert操作例子
	//insert
	//A01 何以笙箫默 顾漫 浙江出版社 20030306 28 10000

	//delete操作例子
	//delete
	//no A01
	while (scanf("%s", cmd) != EOF)
	{
		if (strcmp(cmd, "insert") == 0)
		{
			p=(PNODE)malloc(sizeof(LINK));
			scanf("%s %s %s %s %d %d %d",p->no,p->name,p->writer,p->publisher,&p->date,&p->price,&p->amount);
			count++;
			p->next=head->next;
			head->next=p;
			/*cout<<"--------------------------------------"<<endl;
			p = head->next;
			for(int i = count;i>0;i--) 
			{
				printf("%s %s %s %s %d %d %d\n" ,p->no,p->name,p->writer,p->publisher,p->date,p->price,p->amount);
				p=p->next;
			}
			cout<<"--------------------------------------"<<endl;*/
		}
		if (strcmp(cmd, "delete") == 0)
		{
			char strcmd[20],tmp[20];
			cout<<"delete by no|name|writer|publisher\neg.\nname 琅琊榜\nno A01\n"<<endl;
			//cin>>strcmd>>tmp;
			scanf("%s %s", strcmd, tmp);
			//cout<<strcmd<<endl;
			//delete
			Lnode* prev = head;
			p = head->next;
			while(p != nullptr)
			{
				string myTmp;
				if (strcmp(strcmd, "no") == 0)
				{
					myTmp = p->no;
				}
				else if (strcmp(strcmd, "name") == 0)
				{
					myTmp = p->name;
				}
				else if (strcmp(strcmd, "no") == 0)
				{
					myTmp = p->no;
				}
				else if (strcmp(strcmd, "writer") == 0)
				{
					myTmp = p->writer;
				}
				else if (strcmp(strcmd, "publisher") == 0)
				{
					myTmp = p->publisher;
				}
				else
				{
					cout<<"can not find "<<strcmd<<endl;
					break;
				}
				if (strcmp(tmp, myTmp.c_str()) == 0)
				{
					prev->next = p->next;
					delete p;
					p = prev->next;
					count--;
				}
				else
				{
					prev = p;
					p = p->next;
				}
			}
			cout<<"--------------------------------------"<<endl;
			p = head->next;
			for(int i = count;i>0;i--) 
			{
				printf("%s %s %s %s %d %d %d\n" ,p->no,p->name,p->writer,p->publisher,p->date,p->price,p->amount);
				p=p->next;
			}
			cout<<"--------------------------------------"<<endl;
		}
	}
	fclose(fp);
}
