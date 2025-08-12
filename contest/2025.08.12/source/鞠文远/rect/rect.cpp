#include<bits/stdc++.h>
using namespace std;
const int N=505,S=30;
int n,m,cnt,anslt[N][N];
string ary[N];
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ary[i];
		ary[i]='.'+ary[i];
	}
	for(int c=S;c>=1;c--)
		for(int i=S;i>=1;i--)
		{
			for(int x=1;x<=n-c+1;x++)
				for(int y=1;y<=m-i+1;y++)
				{
					bool pd=true;
					for(int j=x;j<=x+c-1;j++)
					{
						for(int k=y;k<=y+i-1;k++)
							if(anslt[j][k]||ary[j][k]=='B')
							{
								pd=false;
								break;
							}
						if(!pd)break;
					}
					if(!pd)continue;
					cnt++;
					for(int j=x;j<=x+c-1;j++)
						for(int k=y;k<=y+i-1;k++)
							anslt[j][k]=cnt;
			}
		}
	 for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cout<<anslt[i][j]<<" ";
	 	cout<<"\n";
	}
	
	return 0;
} 
