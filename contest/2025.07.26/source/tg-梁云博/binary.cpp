#include <bits/stdc++.h> 
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
#define N 5005
#define pii pair<int,int>
using namespace std;
int m,n;
int del[N];
char g[N][N];
int size[]={0,2,5,11,23,47,95,191,383,767,1535};//倒数第i层的size 
int line[]={0,0,1,2,5,11,23,47,95,191,383};//第i层多占用多少行 
void down(int p)
{
	if(ls<=pow(2,m))
	{
		del[ls]=1;
		down(ls);
	}
	if(rs<=pow(2,m))
	{
		del[rs]=1;
		down(rs);
	}
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>m>>n;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		int p=pow(2,x-1)-1+y;
		del[p]=1;//节点编号 
		down(p);
	}
	int lines=1,nxtl=1;//图中的行,下一层行数 
	for(int i=m;i>=1;i--)//从上向下枚举 
	{
		if(i==1)
		{
			for(int j=1;j<=size[m];j++)
			{
				if(j%6==1 || j%6==5)if(g[lines-1][j-1]=='\\' || g[lines-1][j+1]=='/')g[lines][j]='o';
			}
			
		}
		else
		{
			for(int j=1;j<=size[m];j++)
			{
				int p=i==m?1:(1<<m-i)+j/(size[i]+1);
				if(j%(size[i]+1)==size[i-1]+1)//是节点 
				{
					if(!del[p])
					{
						g[lines][j]='o';
						if(!del[ls])
						{
							for(int k=lines+1;k<=lines+line[i];k++)//向下枚举行数 
							{
								int t=k-lines; 
								g[k][j-t]='/';
							}
						}
						if(!del[rs])
						{
							g[lines][j]='o';
							for(int k=lines+1;k<=lines+line[i];k++)//向下枚举行数 
							{
								int t=k-lines; 
								g[k][j+t]='\\';
							}
						}
					}
				}
				
			}lines+=line[i]+1;
		}
		
	}
	for(int i=1;i<=lines;i++)
	{
		for(int j=1;j<=size[m];j++)
		{
			if(g[i][j]==char(0))cout<<char(32);
			else cout<<g[i][j];
		}if(i!=lines)cout<<"\n";
	}
	return 0;
}
