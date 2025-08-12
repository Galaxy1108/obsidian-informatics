#include<bits/stdc++.h>
using namespace std;
const int mx=510;
int n,m;
char ch[mx][mx];
int a[mx][mx];
struct jux
{
	int l,r,id,line;
}sq[mx];
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			ch[i][j]='B';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			ch[i][j]=c;
			if(ch[i][j]=='B') a[i][j]=0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='C'&&ch[i][j-1]=='B') cnt++,sq[cnt].l=j,sq[cnt].line=i,sq[cnt].id=cnt;
			if(ch[i][j]!='B') a[i][j]=sq[cnt].id;
			if(ch[i][j]=='B'&&ch[i][j-1]=='C')
			{
				sq[cnt].r=j-1;
				for(int k=cnt-1;sq[k].line>=i-1&&k>0;k--)
				{
					if(sq[k].l==sq[cnt].l&&sq[k].r==sq[cnt].r)
					{
						sq[cnt].id=sq[k].id;
						for(int w=sq[cnt].l;w<=sq[cnt].r;w++)
							a[i][w]=sq[k].id;
						cnt--;
						break;
					}
				}
			} 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
