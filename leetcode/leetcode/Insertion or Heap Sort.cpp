//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool perInsertSort(vector<int> &src, vector<int> &dest, int start)
//{
//	int pos = start;
//	int poit = src[start];
//	for (int j = start - 1; j >= 0; --j){//�ҳ�����λ��
//		if (src[j] > poit) {
//			pos = j;
//		}
//		else{
//			break;
//		}
//	}
//	for (int j = start - 1; j >= pos; --j){
//		src[j + 1] = src[j];
//	}
//	src[pos] = poit;
//	if (src == dest) return true;
//	return false;
//}
//
//
///*
//void mergeSort(vector<int> &src,vector<int> &dest,int start,int end,bool &isFind,bool &stop)
//{//ʹ�õݹ�Ĺ鲢����
//if(stop) return;
//if(end - start ==1 ) return;
//int middle = (end+start)/2;
//mergeSort(src,dest,start,middle,isFind,stop);
//mergeSort(src,dest,middle,end,isFind,stop);
//inplace_merge(src.begin()+start,src.begin()+middle,src.begin()+end);
//if(isFind){
//stop = true;
//}
//if(src == dest){
//isFind = true;
//}
//}
//*/
//
//void mergeSort(vector<int> &src, int step)
//{
//	int len = src.size();
//	if (step >= len) return;//������ĳ����Ѿ�����src�ĳ���
//	int i = 0;
//	while (i<len){
//		vector<int>::iterator iter = src.begin();
//		int start = i;
//		int middle = i + step;
//		int end = middle + step;
//		middle = (middle >= len ? len : middle);
//		end = (end >= len ? len : end);
//		inplace_merge(iter + start, iter + middle, iter + end);
//		i = end;
//	}
//}
//
//void print(const vector<int> &src)
//{
//	bool first = true;
//	for (int i = 0; i<src.size(); ++i){
//		if (first){
//			cout << src[i];
//			first = false;
//		}
//		else{
//			cout << " " << src[i];
//		}
//	}
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	int x;
//	vector<int> src, dest;
//	int repeat = n;
//	while (repeat--){
//		cin >> x;
//		src.push_back(x);
//	}
//	repeat = n;
//	while (repeat--){
//		cin >> x;
//		dest.push_back(x);
//	}
//	vector<int> temp(src.begin(), src.end());
//	bool isInsertSort = false;
//	for (int i = 1; i<src.size(); ++i)
//	{
//		isInsertSort = perInsertSort(src, dest, i);
//		if (isInsertSort){
//			cout << "Insertion Sort" << endl;
//			if (i + 1 <= src.size()){
//				perInsertSort(src, dest, i + 1);
//				print(src);
//				cout << endl;
//				break;
//			}
//		}
//	}
//	if (!isInsertSort){
//		int step = 1;
//		while (step < temp.size()){
//			if (temp == dest){
//				cout << "Merge Sort" << endl;
//				mergeSort(temp, step);
//				print(temp);
//				cout << endl;
//				break;
//			}
//			mergeSort(temp, step);
//			step *= 2;
//		}
//	}
//	return 0;
//}
//#include<string>
//#include <iomanip>
#include<vector>
#include <algorithm>
//#include<stack>
#include<set>
#include<queue>
#include<map>
//#include<unordered_set>
#include<unordered_map>
//#include <sstream>
//#include "func.h"
//#include <list>
#include<stdio.h>
#include<iostream>
#include<string>
#include<memory.h>
#include<limits.h>
using namespace std;

/*
10
6 4 5 1 0 3 2 7 8 9
5 4 2 1 0 3 6 7 8 9
*/
#define LeftChild(i) (2*(i)+1)
void PercDown(vector<int>&num, int i, int n)
{
	int child;
	int tmp;
	for (tmp = num[i]; LeftChild(i) < n; i = child)
	{
		child = LeftChild(i);
		if (child != n - 1 && num[child + 1] > num[child])
			child++;
		if (tmp < num[child])
			num[i] = num[child];
		else
			break;
	}
	num[i] = tmp;
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> num(n, 0);
	vector<int> num2(n, 0);
	vector<int> numCopy(n, 0);
	vector<int> target(n, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	numCopy = num;
	num2 = num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &target[i]);
	}

	bool isInsert = false;

	for (int i = 1; i < n; i++)
	{//���в�������,��i=1�����ڶ���Ԫ�ؿ�ʼ��������i=0ʱ��û��Ҫ���в�������Ϊʲô���Ե�2�����
		int tmp = num[i];
		int j = i;
		for (; j > 0 && num[j - 1]>tmp; j--)
		{
			num[j] = num[j - 1];
		}
		num[j] = tmp;
		if (!isInsert && num == target)
		{//�ǲ�������
			isInsert = true;
		}
		else if (isInsert)
		{
			break;
		}
	}
	if (isInsert)
	{
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << num[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << endl;
		return 0;
	}

	bool isHeap = false;
	for (int i = n / 2; i >= 0; i--)
		PercDown(numCopy, i, n);
	for (int i = n - 1; i > 0; i--)
	{//���ж���
		swap(numCopy[0], numCopy[i]);
		PercDown(numCopy, 0, i);
		if (!isHeap && numCopy == target)
		{
			isHeap = true;
		}
		else if (isHeap)
			break;
		//cout << "Heap Sort" << endl;
		//for (int i = 0; i < n; i++)
		//{
		//	cout << numCopy[i];
		//	if (i != n - 1)
		//		cout << " ";
		//}

	}
	if (isHeap)
	{//����Ƕ��ţ������return
		cout << "Heap Sort" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << numCopy[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << endl;
		return 0;
	}
	return 0;
}
