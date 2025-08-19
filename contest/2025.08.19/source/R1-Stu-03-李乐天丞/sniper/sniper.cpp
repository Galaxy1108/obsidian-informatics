#include <bits/stdc++.h>
using namespace std;
const int maxn=8050;
inline int Qread()
{
	int sum=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
	return sum;
}
int f[25050][20];
int w[maxn],u[maxn],t[maxn],n,T;
int v[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int main()
{
	freopen("sinper.in","r",stdin);
	freopen("sinper.out","w",stdout);
	n=Qread();
	for(int i=1;i<=n;i++)
	{
		w[i]=Qread();
		u[i]=Qread();
		t[i]=Qread();
		w[i]=v[w[i]];
	}
	T=t[n];int num=1;
	for(int i=1;i<=T;i++) 
	for(int j=1;j<=20;j++)
	f[i][j]=-1e9;
	for(int i=0;i<=T;i++)
	{
		while(num<=n&&t[num]==i)
		{
			if(w[num]==50) 
			{
				for(int j=1;j<=20;j++) if(j!=u[num]) f[i][j]=-1e9;
			}
		    f[i+1][u[num]]=max(f[i+1][u[num]],f[i][u[num]]+w[num]);
		    num++;
		}
		for(int j=1;j<=20;j++)
		{
			if(j>2) f[i+1][j-2]=max(f[i+1][j-2],f[i][j]);
			if(j>2) f[i+1][j-1]=max(f[i+1][j-1],f[i][j]);
			f[i+1][j]=max(f[i+1][j],f[i][j]);
			if(j<20) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
			if(j<19) f[i+1][j+2]=max(f[i+1][j+2],f[i][j]);
		}
	}
	for(int i=1;i<=20;i++) f[T+1][20]=max(f[T+1][20],f[T+1][i]);
	cout<<f[T+1][20];
	return 0;
}
