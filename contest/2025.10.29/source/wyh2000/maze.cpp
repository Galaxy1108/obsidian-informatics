#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define N 205
#define oo (1<<29)
#define LL long long
using namespace std;
int n,m,Tx,Ty,G[N][N],A[N][N]; LL F[N][N];
int gd(int x,int y){ return (x-1)*m+y;}
void link(int x,int y){ G[x][y]=G[y][x]=1,F[x][y]=F[y][x]=1;}
int main()
{
	int i,j,k;
	freopen("maze.in","r" , stdin);
	freopen("maze.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&Tx,&Ty);
	for(i=1;i<=n*m;i++)
		for(j=1;j<=n*m;j++)
			G[i][j]=(i!=j)*oo;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(A[i][j]) continue;
			if(i>1&&!A[i-1][j]) link(gd(i,j),gd(i-1,j));
			if(j>1&&!A[i][j-1]) link(gd(i,j),gd(i,j-1));
			if(i<n&&!A[i+1][j]) link(gd(i,j),gd(i+1,j));
			if(j<m&&!A[i][j+1]) link(gd(i,j),gd(i,j+1));
		  }
	for(k=1;k<=n*m;k++)
		for(i=1;i<=n*m;i++)
			for(j=1;j<=n*m;j++)
				if(G[i][j]>G[i][k]+G[k][j]) G[i][j]=G[i][k]+G[k][j],F[i][j]=F[i][k]*F[k][j];
				else if(G[i][j]==G[i][k]+G[k][j]) F[i][j]+=F[i][k]*F[k][j];
	cout<<F[1][gd(Tx,Ty)];
	return 0;
}
