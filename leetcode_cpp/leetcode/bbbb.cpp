

#include<iostream>
#include<cstring>
using namespace std;
const int  N=25;
char square[N][N];
bool flag[N][N];
int width,height;

bool isRec(int row,int col,char ch){
	//width
	int temp_width=0;
	for(int j =col;j<width;j++){
		if(square[row][j]==ch){
			temp_width++;
		}
	}
	int temp_height = 0;
	for(int i=row;i<height;i++){
		if(square[i][col]==ch){
			temp_height++;
		}
	}
	bool is = true;
	for(int i=row+1;i<row+temp_height;i++){
		for(int j=col+1;j<col+temp_width;j++){
			if(square[i][j]!=ch){
				is = false;
				break;
			}
		}
		if(!is)
			break;
	}
	if(is){
		for(int i=row;i<row+temp_height;i++){
			for(int j=col;j<col+temp_width;j++){
				flag[i][j]=false;
			}
		}
	}

	return is;
}


int main()
{
	memset(flag,true,sizeof(flag));
	cin>>height>>width;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			cin>>square[i][j];
		}
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){

			if(flag[i][j]&&isRec(i,j,square[i][j])){
				cout<<square[i][j]<<" "<<i+1<<" "<<j+1<<endl;
			}
		}
	}
	system("pause");
	return 0;
}