#include <bits/stdc++.h>
using namespace std;
bool del[800][2000];
int w,h;
int n,m;
char c[800][2000];
void draw(int x,int y,int d,int i,int j)
{
	c[x][y]='o';
	if(i==m) return;	
	int l=j*2-1,r=j*2;
	for(int k=1;k<d;k++)
	{
		if(!del[i+1][l]) c[x+k][y-k]='/';
		if(!del[i+1][r]) c[x+k][y+k]='\\'; 
	}
	if(!del[i+1][l]) draw(x+d,y-d,(d+1)/2,i+1,l);
	if(del[i+1][l]) c[x+d][y-d]=char(32);
	if(!del[i+1][r]) draw(x+d,y+d,(d+1)/2,i+1,r);
	if(del[i+1][r]) c[x+d][y+d]=char(32);
//	for(int i=1;i<=h;i++)
//	{
//		for(int j=1;j<=w;j++)
//		{
//			cout<<c[i][j]; 
//		}
//		cout<<endl;
//	}
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	memset(del,0,sizeof(del));
	cin>>m>>n;
	w=6*pow(2,m-2)-1;
	h=3*pow(2,m-2);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		del[x][y]=true;
	}
	draw(1,w/2+1,(h+1)/2,1,1);
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			printf("%c",c[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
