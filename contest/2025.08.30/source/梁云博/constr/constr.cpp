#include <bits/stdc++.h>
using namespace std;
int path[15][15]={
	{1,2,3,4,5,6,7,8,9,10},
	{10,9,8,7,6,5,4,3,2,1},
};
void print(int x)
{
	for(int i=0;i<10;i++)
	{
		for(int j=i;j<=i+10-1;j++)cout<<path[x][j%10]<<" ";
		cout<<"\n"; 
	}
}

int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cout<<2*370<<"\n";
	for(int x=0;x<2;x++)
	{
		print(x);
		for(int i=0;i<10;i++)//swap 
		{
			for(int j=i+2;j<10;j++)
			{
				swap(path[x][i],path[x][j]);
				print(x);
				swap(path[x][i],path[x][j]);
			}
		}
	}
	return 0;
} 

