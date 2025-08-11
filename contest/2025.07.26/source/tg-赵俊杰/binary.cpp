#include<bits/stdc++.h>
using namespace std;
const int N=105;
int len[N],a[N][1<<13];
struct T
{
	int l,r;
}q[N];
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		int l=y,r=y;
		for(int j=x+1;j<=n;j++)
		{
			l=l*2-1;r=r*2;
			for(int k=l;k<=r;k++)
				a[j][k]=1;
		}
	}
	len[2]=1;
	for(int i=3;i<=n+4;i++)
		for(int j=2;j<i;j++)len[i]+=len[j]+1;
	int o=len[n+2];
	for(int i=1;i<=n;i++)
	{
		int k=len[n-i+2];
		if(i==n)k=0;
		for(int i=1;i<=k;i++)cout<<' ';
		if(!a[i][1])cout<<'o';
		else cout<<' ';
		k=k*2+1;
		for(int j=2;j<=(1<<(i-1));j++)
		{
			if(i==n)
			{
				if(j&1)k=1;
				else k=3;
			}
			for(int p=1;p<=k;p++)cout<<' ';
			if(!a[i][j])cout<<'o';
			else cout<<' ';
		}
		if(i!=n)
		{
		for(int j=1;j<=len[n-i+2];j++)cout<<' ';
		cout<<'\n';
		}
		if(i==n)return 0;
		for(int j=1;j<=(1<<(i-1));j++)
			q[j]={len[n-i+2]+(j-1)*(k+1),len[n-i+2]+(j-1)*(k+1)};
		for(int j=1;j<=len[n-i+1];j++)
		{
			int t=0;
			for(int p=1;p<=(1<<(i-1));p++)
			{
				q[p].l--;
				q[p].r++;
				t++;
				while(t<=q[p].l)
				{
					cout<<' ';
					t++;
				}
				if(a[i][p]||a[i+1][p*2-1])cout<<' ';
				else cout<<'/';
				while(t<q[p].r)
				{
					cout<<' ';
					t++;
				}
				if(a[i][p]||a[i+1][p*2])cout<<' ';
				else cout<<'\\';
				t++;
			}
			while(t<=o)
			{
				cout<<' ';
				t++;
			}
			cout<<'\n';
		}
	}
	return 0;
}
