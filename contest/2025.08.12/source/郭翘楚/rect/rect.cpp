
#include <bits/stdc++.h>
using namespace std;
char s[505][505];
bool cl[505][505];
int nu[505][505];
int main()
{
	freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>s[i][j];
			if(s[i][j]=='B')
			{
				nu[i][j]=0;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='C' and !cl[i][j])
			{
				int k=i;
				while(s[k+1][j]=='C' and !cl[k+1][j] and k+1<=n)
				{
					k++;
				}
				int ku=k-i+1;
				k=j;
				while(s[i][k+1]=='C' and !cl[i][k+1] and k+1<=m)
				{
					k++;
				}
				int ch=k-j+1;
//				if(s[i+1][j]=='C' and s[i][j+1]=='C' and s[i+1][j+1]=='C' and ch<4 and ku<4)
//				{
//					cnt++;
//					nu[i][j]=nu[i+1][j]=nu[i][j+1]=nu[i+1][j+1]=cnt;
//					cl[i][j]=cl[i+1][j]=cl[i][j+1]=cl[i+1][j+1]=true;
//					continue;
//				}
//				if(s[i+1][j]=='C' and s[i][j+1]=='C' and s[i+1][j+1]=='C' and s[i+2][j]=='C' and s[i][j+2]=='C' and s[i+1][j+2]=='C' and s[i+2][j+1]=='C' and s[i+2][j+2]=='C' and ch<9 and ku<9)
//				{
//					cnt++;
//					nu[i][j]=nu[i+1][j]=nu[i][j+1]=nu[i+1][j+1]=nu[i+1][j+2]=nu[i+2][j+1]=nu[i+2][j+2]=nu[i][j+2]=nu[i+2][j]=cnt;
//					cl[i][j]=cl[i+1][j]=cl[i][j+1]=cl[i+1][j+1]=nu[i+1][j+2]=nu[i+2][j+1]=nu[i+2][j+2]=nu[i][j+2]=nu[i+2][j]=true;
//					continue;
//				}
				if(ku>=ch)
				{
					cnt++;
					for(int x=0;x<ku;x++)
					{
						nu[x+i][j]=cnt;
						cl[x+i][j]=true;
					}
					continue;
				}
				else
				{
					cnt++;
					for(int y=0;y<ch;y++)
					{
						nu[i][y+j]=cnt;
						cl[i][y+j]=true;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<nu[i][j]<<" "; 
		}
		cout<<endl;
	}
	return 0;
}
